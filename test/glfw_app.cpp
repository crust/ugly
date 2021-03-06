#include "glfw_app.h"
#include "log.h"
#include "ugly.h"

bool glfwApp::_done { true };
std::atomic<int> glfwApp::_refs { 0 };

void glfwApp::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
  _done = true;
}

void glfwApp::on_error(int err, const char* message) {
  loge("glfw error %d: %s", err, message);
  throw 1;
}

glfwApp::glfwApp(int major, int minor) {
  if (!_refs) {
    glfwSetErrorCallback(on_error);
    glfwInit();
  }
  ++_refs;

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, true);

  _window = glfwCreateWindow(width(), height(), "libugly test", NULL, NULL);

  glfwMakeContextCurrent(_window);

  _done = false;

  glfwSetKeyCallback(_window, key_callback);
}

glfwApp::~glfwApp() {
  glfwDestroyWindow(_window);
  --_refs;
  if (!_refs) {
    glfwTerminate();
  }
}

void glfwApp::update() {
  glfwPollEvents();
  glfwSwapBuffers(_window);
}

void glfwApp::make_current() {
  glfwMakeContextCurrent(_window);
}

bool glfwApp::done() const {
  return _done;
}

int glfwApp::width() const {
  return 720 * (16.0 / 9.0);
}

int glfwApp::height() const {
  return 720;
}

