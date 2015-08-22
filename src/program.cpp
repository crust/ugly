#include "program.h"
#include "log.h"
#include "gl_type.h"

namespace gl {

template<void(*f0)(GLuint, GLenum, GLint*), void(*f1)(GLuint, GLsizei, GLsizei*, GLchar*)>
void gl_log(GLuint id);

static inline void print_log(GLuint id) {
  gl_log<glGetProgramiv, glGetProgramInfoLog>(id);
}


class Program_impl;

#define _name ((GLuint&)*_impl)


Program::Program(): _impl((Program_impl*)new GLuint(0)) {
  GL_CALL(_name = glCreateProgram());
}

Program::~Program() {
  GL_CALL(glDeleteProgram(_name));
  delete (GLuint*)_impl;
}

void Program::attach(Shader const& shader) {
  GL_VALIDATE(Shader, shader.name());
  GL_CALL(glAttachShader(_name, shader.name()));
}

void Program::detach(Shader const& shader) {
  GL_VALIDATE(Shader, shader.name());
  GL_CALL(glDetachShader(_name, shader.name()));
}


void Program::link() {
  GL_VALIDATE(Program, name());
  GL_CALL(glLinkProgram(_name));

  int success = GL_FALSE;
  glGetProgramiv(_name, GL_LINK_STATUS, &success);

  if (success != GL_TRUE) {
    print_log(_name);
    throw gl::exception("failed to link program %u", _name);
  }
}

void Program::use(IContext const& context) {
  if (!context.current()) {
    throw gl::exception("attempt to use program with non-current context");
  }
  GL_CALL(glUseProgram(_name));
}

GLuint Program::name() const {
  return _name;
}

}

