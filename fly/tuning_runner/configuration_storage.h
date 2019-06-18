#pragma once

#include <map>
#include <vector>
#include <fly/kernel/kernel_configuration.h>
#include <fly/kernel/kernel_parameter_pack.h>

namespace fly
{

class ConfigurationStorage
{
public:
    void storeConfiguration(const std::pair<KernelConfiguration, uint64_t>& configuration);
    void storeProcessedPack(const KernelParameterPack& pack);
    KernelConfiguration getBestCompatibleConfiguration(const KernelParameterPack& currentPack,
        const std::vector<ParameterPair>& generatedPairs) const;

private:
    std::vector<KernelParameterPack> processedPacks;
    std::multimap<uint64_t, KernelConfiguration> orderedConfigurations;

    bool isConfigurationCompatible(const KernelConfiguration& configuration, const KernelParameterPack& currentPack,
        const std::vector<ParameterPair>& generatedPairs) const;
};

} // namespace fly
