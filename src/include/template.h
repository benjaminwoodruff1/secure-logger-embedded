// template.h
// Example header file that defines symbols that go in a library later

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _template {
    // Data members
    int a;
    int b;
} template_t;

// Calculates a + b of a template struct
int template_sum(template_t t);

// Calculates a / b of a stemplate struct
int template_divide(template_t t);

#ifdef __cplusplus
}
#endif
