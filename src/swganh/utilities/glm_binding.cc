// This file is part of SWGANH which is released under the MIT license.
// See file LICENSE or go to http://swganh.com/LICENSE

#include <swganh/scripting/utility_python.h>
#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

#include <boost/python.hpp>
using namespace boost::python;
namespace swganh
{
namespace utilities
{
std::string pretty_print_vec3(glm::vec3 vector)
{
    std::stringstream ss;
    ss << "(x=" << vector.x << ",y=" << vector.y << ",z=" << vector.z << ")";
    return ss.str();
}

std::string pretty_print_quat(glm::quat quaternion)
{
    std::stringstream ss;
    ss << "(x=" << quaternion.x << ",y=" << quaternion.y << ",z=" << quaternion.z << ",w=" << quaternion.w << ")";
    return ss.str();
}

void define_class_glm_vec3()
{
    class_<glm::vec3>("vector3",
                      "Stores a direction vector in three-dimensional space")
    .def(init<glm::float_t, glm::float_t, glm::float_t>())
    .def(init<const glm::vec3&>())
    .def_readwrite("x", &glm::vec3::x)
    .def_readwrite("y", &glm::vec3::y)
    .def_readwrite("z", &glm::vec3::z)
    .def("__len__", &utility::constant_len_len<glm::vec3, 3>)
    .def("__getitem__", &utility::constant_len_get_item<glm::vec3, 3, glm::float_t>)
    .def("__setitem__", &utility::constant_len_set_item<glm::vec3, 3, glm::float_t>)
    .def("__str__", &pretty_print_vec3)
    .def(self == self)
    .def(self != self)
    .def(self + self)
    .def(self - self)
    .def(self * glm::float_t())
    .def(glm::float_t() * self)
    .def(self += self)
    .def(self -= self)
    .def(self *= glm::float_t())
    .def(self /= glm::float_t());
    //.def(self_ns::str(self));
}
void define_class_glm_quat()
{
    class_<glm::quat>("quat",
                      "Stores a quaternion")
    .def(init<glm::float_t, glm::float_t, glm::float_t, glm::float_t>())
    .def(init<const glm::quat&>())
    .def_readwrite("x", &glm::quat::x)
    .def_readwrite("y", &glm::quat::y)
    .def_readwrite("z", &glm::quat::z)
    .def_readwrite("w", &glm::quat::w)
    .def("__len__", &utility::constant_len_len<glm::quat, 4>)
    .def("__getitem__", &utility::constant_len_get_item<glm::quat, 4, glm::float_t>)
    .def("__setitem__", &utility::constant_len_set_item<glm::quat, 4, glm::float_t>)
    .def("__str__", &pretty_print_quat)
    .def(self == self)
    .def(self != self)
    /*.def(self + self)
    .def(self - self)*/
    .def(self * glm::float_t())
    .def(glm::float_t() * self)
    /*.def(self += self)
    .def(self -= self)*/
    .def(self *= glm::float_t())
    .def(self /= glm::float_t());
    //.def(self_ns::str(self));
}
}
} // namespace swganh::utilities