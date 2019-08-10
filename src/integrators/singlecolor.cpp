// integrators/singlecolor.cpp*
#include "integrators/singlecolor.h"
#include "sampling.h"
#include "interaction.h"
#include "paramset.h"
#include "camera.h"
#include "film.h"
#include "scene.h"

namespace pbrt {

// SingleColorIntegrator Method Definitions
SingleColorIntegrator::SingleColorIntegrator(
    const Spectrum &inColor, std::shared_ptr<const Camera> camera,
    std::shared_ptr<Sampler> sampler, const Bounds2i &pixelBounds)
    : color(inColor), SamplerIntegrator(camera, sampler, pixelBounds) {
}

Spectrum SingleColorIntegrator::Li(const RayDifferential &r, const Scene &scene,
                          Sampler &sampler, MemoryArena &arena,
                          int depth) const {
    Spectrum L(0.f);
    return L;
}

SingleColorIntegrator *CreateSingleColorIntegrator(const ParamSet &params,
                                 std::shared_ptr<Sampler> sampler,
                                 std::shared_ptr<const Camera> camera) {
    Spectrum color = params.FindOneSpectrum("color", Spectrum(1.f));
    return new SingleColorIntegrator(color, camera, sampler,
                                     camera->film->GetSampleBounds());
}

}  // namespace pbrt
