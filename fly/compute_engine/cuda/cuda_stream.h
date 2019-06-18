#pragma once

#include <string>
#include <cuda.h>
#include <fly/compute_engine/cuda/cuda_utility.h>
#include "fly/fly_types.h"

namespace fly
{

class CUDAStream
{
public:
    explicit CUDAStream(const QueueId id, const CUcontext context, const CUdevice device) :
        id(id),
        context(context),
        device(device)
    {
        checkCUDAError(cuStreamCreate(&stream, CU_STREAM_DEFAULT), "cuStreamCreate");
    }

    ~CUDAStream()
    {
        checkCUDAError(cuStreamDestroy(stream), "cuStreamDestroy");
    }

    QueueId getId() const
    {
        return id;
    }

    CUcontext getcontext() const
    {
        return context;
    }

    CUdevice getDevice() const
    {
        return device;
    }

    CUstream getStream() const
    {
        return stream;
    }

private:
    QueueId id;
    CUcontext context;
    CUdevice device;
    CUstream stream;
};

} // namespace fly
