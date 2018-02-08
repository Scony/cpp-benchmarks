#include <regex>
#include <map>
#include <unordered_map>

#include <benchmark/benchmark.h>

using Collection = std::map<std::string, int>;

unsigned basicRegexCounter(const Collection& c, const std::string& pattern)
{
  unsigned ret = 0;
  std::regex patt(pattern);
  for (const auto& kv : c)
    if (std::regex_match(kv.first, patt))
      ret++;
  return ret;
}

unsigned mapCacheRegexCounter(const Collection& c,
			      const std::string& pattern,
			      std::map<std::pair<std::string, std::string>, bool>& cache)
{
  unsigned ret = 0;
  std::regex patt(pattern);
  for (const auto& kv : c)
    {
      auto it = cache.find({kv.first, pattern});
      if (it == cache.end())
	{
	  auto tmp = cache.emplace(std::make_pair(kv.first, pattern),
				   std::regex_match(kv.first, patt));
	  it = tmp.first;
	}
      if (it->second)
	ret++;
    }
  return ret;
}

unsigned uMapCacheRegexCounter(const Collection& c,
			       const std::string& pattern,
			       std::unordered_map<std::string, bool>& cache)
{
  unsigned ret = 0;
  std::regex patt(pattern);
  for (const auto& kv : c)
    {
      auto key = pattern + ";" + kv.first;
      auto it = cache.find(key);
      if (it == cache.end())
	{
	  auto tmp = cache.emplace(key, std::regex_match(kv.first, patt));
	  it = tmp.first;
	}
      if (it->second)
	ret++;
    }
  return ret;
}

unsigned u2MapCacheRegexCounter(const Collection& c,
				const std::string& pattern,
				std::unordered_map<std::string,
				std::unordered_map<std::string, bool> >& cache)
{
  unsigned ret = 0;

  auto it1 = cache.find(pattern);
  if (it1 == cache.end())
    {
      auto tmp = cache.emplace(pattern, std::unordered_map<std::string, bool>{});
      it1 = tmp.first;
    }
  std::regex patt(pattern);

  for (const auto& kv : c)
    {
      auto it2 = it1->second.find(kv.first);
      if (it2 == it1->second.end())
	{
	  auto tmp = it1->second.emplace(kv.first, std::regex_match(kv.first, patt));
	  it2 = tmp.first;
	}
      if (it2->second)
	ret++;
    }
  return ret;
}

static void BasicRegexCounter(benchmark::State& state)
{
  Collection c;
  for (size_t i = 0; i < state.range(0); i++)
    c.emplace(std::to_string(rand()), 1337);
  for (auto _ : state)
    benchmark::DoNotOptimize(basicRegexCounter(c, ".*123"));
  state.SetComplexityN(state.range(0));
}
BENCHMARK(BasicRegexCounter)->RangeMultiplier(2)->Range(1, 8 << 9)->Complexity(benchmark::oNLogN);

static void MapCacheRegexCounterWEmptyCache(benchmark::State& state)
{
  Collection c;
  for (size_t i = 0; i < state.range(0); i++)
    c.emplace(std::to_string(rand()), 1337);
  std::map<std::pair<std::string, std::string>, bool> cache;
  for (auto _ : state)
    benchmark::DoNotOptimize(mapCacheRegexCounter(c, ".*" + std::to_string(rand() % 100), cache));
  state.SetComplexityN(state.range(0));
}
BENCHMARK(MapCacheRegexCounterWEmptyCache)->RangeMultiplier(2)->Range(1, 8 << 9)->Complexity();

static void MapCacheRegexCounterWFullCache(benchmark::State& state)
{
  Collection c;
  for (size_t i = 0; i < state.range(0); i++)
    c.emplace(std::to_string(rand()), 1337);
  std::map<std::pair<std::string, std::string>, bool> cache;
  for (int i = 0; i < 100; i++)
    mapCacheRegexCounter(c, ".*" + std::to_string(i), cache);
  assert(cache.size() == c.size() * 100);
  for (auto _ : state)
    benchmark::DoNotOptimize(mapCacheRegexCounter(c, ".*" + std::to_string(rand() % 100), cache));
  state.SetComplexityN(state.range(0));
}
BENCHMARK(MapCacheRegexCounterWFullCache)->RangeMultiplier(2)->Range(1, 8 << 9)->Complexity();

static void UMapCacheRegexCounterWEmptyCache(benchmark::State& state)
{
  Collection c;
  for (size_t i = 0; i < state.range(0); i++)
    c.emplace(std::to_string(rand()), 1337);
  std::unordered_map<std::string, bool> cache;
  for (auto _ : state)
    benchmark::DoNotOptimize(uMapCacheRegexCounter(c, ".*" + std::to_string(rand() % 100), cache));
  state.SetComplexityN(state.range(0));
}
BENCHMARK(UMapCacheRegexCounterWEmptyCache)->RangeMultiplier(2)->Range(1, 8 << 9)->Complexity();

static void UMapCacheRegexCounterWFullCache(benchmark::State& state)
{
  Collection c;
  for (size_t i = 0; i < state.range(0); i++)
    c.emplace(std::to_string(rand()), 1337);
  std::unordered_map<std::string, bool> cache;
  for (int i = 0; i < 100; i++)
    uMapCacheRegexCounter(c, ".*" + std::to_string(i), cache);
  assert(cache.size() == c.size() * 100);
  for (auto _ : state)
    benchmark::DoNotOptimize(uMapCacheRegexCounter(c, ".*" + std::to_string(rand() % 100), cache));
  state.SetComplexityN(state.range(0));
}
BENCHMARK(UMapCacheRegexCounterWFullCache)->RangeMultiplier(2)->Range(1, 8 << 9)->Complexity();

static void U2MapCacheRegexCounterWEmptyCache(benchmark::State& state)
{
  Collection c;
  for (size_t i = 0; i < state.range(0); i++)
    c.emplace(std::to_string(rand()), 1337);
  std::unordered_map<std::string, std::unordered_map<std::string, bool> > cache;
  for (auto _ : state)
    benchmark::DoNotOptimize(u2MapCacheRegexCounter(c, ".*" + std::to_string(rand() % 100), cache));
  state.SetComplexityN(state.range(0));
}
BENCHMARK(U2MapCacheRegexCounterWEmptyCache)->RangeMultiplier(2)->Range(1, 8 << 9)->Complexity();

static void U2MapCacheRegexCounterWFullCache(benchmark::State& state)
{
  Collection c;
  for (size_t i = 0; i < state.range(0); i++)
    c.emplace(std::to_string(rand()), 1337);
  std::unordered_map<std::string, std::unordered_map<std::string, bool> > cache;
  for (int i = 0; i < 100; i++)
    u2MapCacheRegexCounter(c, ".*" + std::to_string(i), cache);
  assert(cache.size() == 100);
  for (auto _ : state)
    benchmark::DoNotOptimize(u2MapCacheRegexCounter(c, ".*" + std::to_string(rand() % 100), cache));
  state.SetComplexityN(state.range(0));
}
BENCHMARK(U2MapCacheRegexCounterWFullCache)->RangeMultiplier(2)->Range(1, 8 << 9)->Complexity(benchmark::oNLogN);
