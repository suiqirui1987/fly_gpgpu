#pragma once

#include <map>
#include <memory>
#include <utility>
#include <vector>
#include <fly/api/stop_condition/stop_condition.h>
#include <fly/api/device_info.h>
#include <fly/dto/kernel_result.h>
#include <fly/kernel/kernel_manager.h>
#include <fly/kernel_argument/argument_manager.h>
#include <fly/tuning_runner/configuration_manager.h>
#include <fly/tuning_runner/kernel_runner.h>

namespace fly
{

class TuningRunner
{
public:
    // Constructor
    explicit TuningRunner(ArgumentManager* argumentManager, KernelManager* kernelManager, KernelRunner* kernelRunner, const DeviceInfo& info);

    // Core methods
    std::vector<KernelResult> tuneKernel(const KernelId id, std::unique_ptr<StopCondition> stopCondition);
    std::vector<KernelResult> dryTuneKernel(const KernelId id, const std::string& filePath, const size_t iterations);
    std::vector<KernelResult> tuneComposition(const KernelId id, std::unique_ptr<StopCondition> stopCondition);
    KernelResult tuneKernelByStep(const KernelId id, const KernelRunMode mode, const std::vector<OutputDescriptor>& output,
        const bool recomputeReference);
    KernelResult tuneCompositionByStep(const KernelId id, const KernelRunMode mode, const std::vector<OutputDescriptor>& output,
        const bool recomputeReference);
    void clearKernelData(const KernelId id, const bool clearConfigurations);
    void setKernelProfiling(const bool flag);
    void setSearchMethod(const SearchMethod method, const std::vector<double>& arguments);
    ComputationResult getBestComputationResult(const KernelId id) const;

private:
    // Attributes
    ArgumentManager* argumentManager;
    KernelManager* kernelManager;
    KernelRunner* kernelRunner;
    ConfigurationManager configurationManager;

    // Helper methods
    bool hasWritableZeroCopyArguments(const Kernel& kernel);
};

} // namespace fly
