#pragma once

// This file is ment to be included everywhere in the
// project and contains the base types aswell as the base
// libraries needed for C++ and the engine itself.

#include <inttypes.h>
#include <glm/glm.hpp>

// C++ std-libs
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <fstream>
#include <sstream>

// Creating costum types for more percise coding.
typedef int8_t		i8;
typedef int16_t		i16;
typedef int32_t		i32;
typedef int64_t		i64;
typedef uint8_t		u8;
typedef uint16_t	u16;
typedef uint32_t	u32;
typedef uint64_t	u64;
typedef float		f32;
typedef double		f64;

// Redifining the vectors for convenience.
typedef glm::vec1	Vec1;
typedef glm::vec2	Vec2;
typedef glm::vec3	Vec3;
typedef glm::vec4	Vec4;

typedef glm::mat2	Mat2;
typedef glm::mat3	Mat3;
typedef glm::mat4	Mat4;