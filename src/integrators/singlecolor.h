#if defined(_MSC_VER)
#define NOMINMAX
#pragma once
#endif

#ifndef PBRT_INTEGRATORS_SINGLECOLOR_H
#define PBRT_INTEGRATORS_SINGLECOLOR_H

// integrators/ao.h*
#include "pbrt.h"
#include "integrator.h"

namespace pbrt {

// SingleColorIntegrator Declarations
class SingleColorIntegrator : public SamplerIntegrator
{
  public:
    // SingleColorIntegrator Public Methods
    SingleColorIntegrator(const Spectrum &color,
                          std::shared_ptr<const Camera> camera,
                          std::shared_ptr<Sampler> sampler,
                          const Bounds2i &pixelBounds);
    Spectrum Li(const RayDifferential &ray, const Scene &scene,
                Sampler &sampler, MemoryArena &arena, int depth) const;
 private:
    Spectrum color;
};

SingleColorIntegrator *CreateSingleColorIntegrator(const ParamSet &params,
                                 std::shared_ptr<Sampler> sampler,
                                 std::shared_ptr<const Camera> camera);

}  // namespace pbrt

#endif  // PBRT_INTEGRATORS_SINGLECOLOR_H
