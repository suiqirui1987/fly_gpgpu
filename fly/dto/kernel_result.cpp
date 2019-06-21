#include <limits>
#include <fly/dto/kernel_result.h>

namespace fly
{

KernelResult::KernelResult() :
    kernelName(""),
    computationDuration(std::numeric_limits<uint64_t>::max()),
    overhead(0),
    errorMessage(""),
    valid(false)
{}

KernelResult::KernelResult(const std::string& kernelName, const KernelConfiguration& configuration) :
    kernelName(kernelName),
    configuration(configuration),
    computationDuration(std::numeric_limits<uint64_t>::max()),
    overhead(0),
    errorMessage(""),
    valid(true)
{}

KernelResult::KernelResult(const std::string& kernelName, uint64_t computationDuration) :
    kernelName(kernelName),
    computationDuration(computationDuration),
    overhead(0),
    errorMessage(""),
    valid(true)
{}

KernelResult::KernelResult(const std::string& kernelName, const KernelConfiguration& configuration, const std::string& errorMessage) :
    kernelName(kernelName),
    configuration(configuration),
    computationDuration(std::numeric_limits<uint64_t>::max()),
    overhead(0),
    errorMessage(errorMessage),
    valid(false)
{}

void KernelResult::setKernelName(const std::string& kernelName)
{
    this->kernelName = kernelName;
}

void KernelResult::setConfiguration(const KernelConfiguration& configuration)
{
    this->configuration = configuration;
}

void KernelResult::setComputationDuration(const uint64_t computationDuration)
{
    this->computationDuration = computationDuration;
}

void KernelResult::setOverhead(const uint64_t overhead)
{
    this->overhead = overhead;
}

void KernelResult::setErrorMessage(const std::string& errorMessage)
{
    this->errorMessage = errorMessage;
}


void KernelResult::setValid(const bool flag)
{
    this->valid = flag;
}

const std::string& KernelResult::getKernelName() const
{
    return kernelName;
}

const KernelConfiguration& KernelResult::getConfiguration() const
{
    return configuration;
}

uint64_t KernelResult::getComputationDuration() const
{
    return computationDuration;
}

uint64_t KernelResult::getOverhead() const
{
    return overhead;
}

const std::string& KernelResult::getErrorMessage() const
{
    return errorMessage;
}

bool KernelResult::isValid() const
{
    return valid;
}

void KernelResult::increaseOverhead(const uint64_t overhead)
{
    this->overhead += overhead;
}

} // namespace fly
