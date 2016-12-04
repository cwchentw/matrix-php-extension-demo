#include <phpcpp.h>
#include <matrix.h>

class Matrix : public Php::Base
{
private:
  void* m;
public:
  Matrix() = default;
  ~Matrix();
  void __construct(Php::Parameters&); // PHP constructor
  Php::Value get_at(Php::Parameters&);
  void set_at(Php::Parameters&);
};

Matrix::~Matrix()
{
  matrix_free(this->m);
}

void Matrix::__construct(Php::Parameters &params)
{
  this->m = matrix_new((int32_t)params[0], (int32_t)params[1]);
}

Php::Value Matrix::get_at(Php::Parameters &params)
{
  return matrix_get_at(this->m, (int32_t)params[0], (int32_t)params[1]);
}

void Matrix::set_at(Php::Parameters &params)
{
  matrix_set_at(this->m, (double)params[0],
                (int32_t)params[1], (int32_t)params[2]);
}

/**
 *  tell the compiler that the get_module is a pure C function
 */
extern "C" {

    /**
     *  Function that is called by PHP right after the PHP process
     *  has started, and that returns an address of an internal PHP
     *  strucure with all the details and features of your extension
     *
     *  @return void*   a pointer to an address that is understood by PHP
     */
    PHPCPP_EXPORT void *get_module()
    {
        // static(!) Php::Extension object that should stay in memory
        // for the entire duration of the process (that's why it's static)
        static Php::Extension extension("matrix", "1.0");

        Php::Class<Matrix> matrix("Matrix");
        matrix.method<&Matrix::__construct>("__construct", {
            Php::ByVal("row", Php::Type::Numeric),
              Php::ByVal("col", Php::Type::Numeric)
              });
        matrix.method<&Matrix::get_at>("get_at", {
            Php::ByVal("row", Php::Type::Numeric),
              Php::ByVal("col", Php::Type::Numeric)
              });
        matrix.method<&Matrix::set_at>("set_at", {
            Php::ByVal("value", Php::Type::Float),
              Php::ByVal("row", Php::Type::Numeric),
              Php::ByVal("col", Php::Type::Numeric)
              });

        extension.add(std::move(matrix));

        // return the extension
        return extension;
    }
}
