#pragma once

#include <cstdint>
#include <span>

namespace h3::values
{
template<typename T>
void skipVal(size_t &idx, const T &val)
{
    idx += sizeof(val);
}

template<typename T, size_t N>
void readArr(const std::span<const char> &data, size_t &idx, T (&val)[N])
{
    memcpy(val, &data[idx], sizeof(val));
    idx += sizeof(val);
}

template<typename T>
void readVal(const std::span<const char> &data, size_t &idx, T &val)
{}

void readVal(const std::span<const char> &data, size_t &idx, uint8_t &val);
void readVal(const std::span<const char> &data, size_t &idx, uint16_t &val);
void readVal(const std::span<const char> &data, size_t &idx, uint32_t &val);
} // namespace h3::values