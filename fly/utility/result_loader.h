#pragma once

#include <cstddef>
#include <map>
#include <string>
#include <vector>
#include <fly/dto/kernel_result.h>
#include <fly/enum/time_unit.h>

namespace fly
{

class ResultLoader
{
public:
    bool loadResults(const std::string& filePath);
    KernelResult readResult(const KernelConfiguration& configuration);

private:
    std::vector<std::vector<int>> values;
    int timeIndex;
    size_t paramsBegin;
    size_t paramsLength;
};

} // namespace fly
