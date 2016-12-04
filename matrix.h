#ifndef __MATRIX_H_
#define __MATRIX_H_

#ifdef __cplusplus
extern "C" {
#endif

  void* matrix_new(size_t, size_t);
  double matrix_get_at(void*, size_t, size_t);
  void matrix_set_at(void*, double, size_t, size_t);
  void matrix_free(void*);

#ifdef __cplusplus
}
#endif

#endif // __MATRIX_H_
