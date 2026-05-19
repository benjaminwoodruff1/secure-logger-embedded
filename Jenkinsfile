pipeline {
  agent any
  options {
    timestamps()
    skipDefaultCheckout()  // Skip auto download of SCM so we can clean up first
  }

  stages {
    stage('Build') {  // Build stage: Compile the component
      steps {
        echo "Before starting build, cleaning up previous workspace, if any"
        cleanWs()

        echo "Starting component checkout and build..."
        bitbucketStatusNotify(buildState: 'INPROGRESS')
        timeout(time:10) {  // Timeout after 10 minutes
          checkout scm
          sh 'cmake -DCMAKE_BUILD_TYPE=Debug -B build'
        }
        echo "Finished component build!"
      }
    }

    stage('Unit Test') {  // Test stage: Perform UT on compiled component
      steps {
        echo "Starting component UT..."
        timeout(time:10) {
          dir('build') {
            sh 'make check'
          }
        }
        echo "Finished component UT!"
      }
    }

    stage('Deploy') {  // Deploy stage: Tag latest commit, and release it
      when { branch "master" }
      environment {
        // This will be the tag we will attach to the latest commit, which at
        // this point has passed its build
        GIT_TAG = "cd$BUILD_NUMBER"
      }
      steps {
        echo "Starting component deploy..."
        timeout(time:10) {
          sshagent(['7b5fd228-92e3-43f1-87aa-952f8dcb0fcc']) {
            // Set the git username and email for Jenkins automation
            sh 'git config user.name "Jenkins"'
            sh 'git config user.email "noreply@btltechs.com"'

            // Tag the latest build with a cdlabel, and update the "latest" tag
            sh 'git tag -af latest_passed -m "[Jenkins Automation] Latest passed build tag"'
            sh 'git tag -af \$GIT_TAG -m "[Jenkins Automation] Component cdlabel tag (\$GIT_TAG)"'
            sh 'git push -f origin --tags'
          }
        }
        echo "Finished component deploy!"
      }
    }
  }

  post {
    // If you want to archive build artifacts, you can do it here
    // This is disabled for the component template
    //always {
    //  archiveArtifacts artifacts: 'build/*', followSymlinks: false
    //}

    success {
      bitbucketStatusNotify(buildState: 'SUCCESSFUL')
    }

    failure {
      bitbucketStatusNotify(buildState: 'FAILED')
    }
  }

}
