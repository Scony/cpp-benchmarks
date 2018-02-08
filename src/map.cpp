#include <map>
#include <unordered_map>

#include <benchmark/benchmark.h>

static void MapLookup(benchmark::State& state)
{
  std::map<std::string, int> map;
  for (size_t i = 0; i < state.range(0); i++)
    map.emplace(std::to_string(rand()), 1337);
  for (auto _ : state)
    benchmark::DoNotOptimize(map.find("1e1s3-0dp3d3;'4f590ghnbjfkcb"));
  state.SetComplexityN(state.range(0));
}
BENCHMARK(MapLookup)->Range(1, 8 << 15)->Complexity();

static void UMapLookup(benchmark::State& state)
{
  std::unordered_map<std::string, int> map;
  for (size_t i = 0; i < state.range(0); i++)
    map.emplace(std::to_string(rand()), 1337);
  for (auto _ : state)
    benchmark::DoNotOptimize(map.find("1e1s3-0dp3d3;'4f590ghnbjfkcb"));
  state.SetComplexityN(state.range(0));
}
BENCHMARK(UMapLookup)->Range(1, 8 << 15)->Complexity();
