```
------------------------------------------------------------------------------
Benchmark                                       Time           CPU Iterations
------------------------------------------------------------------------------
StringCopy                                     36 ns         36 ns   19219649
MapLookup/1                                   203 ns        202 ns    2930164
MapLookup/8                                   353 ns        352 ns    1922247
MapLookup/64                                  514 ns        514 ns    1000000
MapLookup/512                                 687 ns        687 ns    1298497
MapLookup/4096                                657 ns        657 ns     992940
MapLookup/32768                               902 ns        902 ns     739062
MapLookup/262144                              946 ns        945 ns     624957
MapLookup_BigO                              59.54 lgN      59.52 lgN 
MapLookup_RMS                                  23 %         23 % 
UMapLookup/1                                  235 ns        235 ns    3267944
UMapLookup/8                                  300 ns        300 ns    2695580
UMapLookup/64                                 235 ns        235 ns    2285741
UMapLookup/512                                216 ns        216 ns    3243725
UMapLookup/4096                               216 ns        216 ns    2331923
UMapLookup/32768                              301 ns        301 ns    2686794
UMapLookup/262144                             215 ns        215 ns    2702114
UMapLookup_BigO                            245.47 (1)     245.33 (1) 
UMapLookup_RMS                                 15 %         15 % 
BasicRegexCounter/1                         15724 ns      15724 ns      45546
BasicRegexCounter/2                         19588 ns      19588 ns      35626
BasicRegexCounter/4                         27713 ns      27712 ns      24395
BasicRegexCounter/8                         43773 ns      43761 ns      15948
BasicRegexCounter/16                        77049 ns      77049 ns       9030
BasicRegexCounter/32                       139537 ns     139407 ns       4932
BasicRegexCounter/64                       270940 ns     270804 ns       2581
BasicRegexCounter/128                      531502 ns     530646 ns       1320
BasicRegexCounter/256                     1048584 ns    1048025 ns        665
BasicRegexCounter/512                     2092756 ns    2089544 ns        334
BasicRegexCounter/1024                    4173205 ns    4171754 ns        168
BasicRegexCounter/2048                    8329450 ns    8320534 ns         84
BasicRegexCounter/4096                   16651338 ns   16651097 ns         42
BasicRegexCounter_BigO                     347.41 NlgN     347.33 NlgN 
BasicRegexCounter_RMS                          12 %         12 % 
MapCacheRegexCounterWEmptyCache/1           11012 ns      11012 ns      63234
MapCacheRegexCounterWEmptyCache/2           11998 ns      11980 ns      58101
MapCacheRegexCounterWEmptyCache/4           14030 ns      14021 ns      48849
MapCacheRegexCounterWEmptyCache/8           18589 ns      18569 ns      36981
MapCacheRegexCounterWEmptyCache/16          28233 ns      28218 ns      24384
MapCacheRegexCounterWEmptyCache/32          49464 ns      49422 ns      10829
MapCacheRegexCounterWEmptyCache/64          94191 ns      94189 ns       5715
MapCacheRegexCounterWEmptyCache/128        201118 ns     201072 ns       3021
MapCacheRegexCounterWEmptyCache/256        473058 ns     473046 ns       1207
MapCacheRegexCounterWEmptyCache/512       1409440 ns    1407382 ns        429
MapCacheRegexCounterWEmptyCache/1024      5093577 ns    5093477 ns        104
MapCacheRegexCounterWEmptyCache/2048     12070019 ns   11994568 ns         52
MapCacheRegexCounterWEmptyCache/4096     27198871 ns   27161333 ns         26
MapCacheRegexCounterWEmptyCache_BigO       546.25 NlgN     545.09 NlgN 
MapCacheRegexCounterWEmptyCache_RMS            11 %         11 % 
MapCacheRegexCounterWFullCache/1            10948 ns      10939 ns      63761
MapCacheRegexCounterWFullCache/2            11955 ns      11940 ns      58457
MapCacheRegexCounterWFullCache/4            14049 ns      14039 ns      49376
MapCacheRegexCounterWFullCache/8            18723 ns      18689 ns      37525
MapCacheRegexCounterWFullCache/16           28958 ns      28794 ns      24282
MapCacheRegexCounterWFullCache/32           48896 ns      48804 ns      14449
MapCacheRegexCounterWFullCache/64           91232 ns      91062 ns       7710
MapCacheRegexCounterWFullCache/128         179547 ns     179376 ns       3835
MapCacheRegexCounterWFullCache/256         378188 ns     377336 ns       1855
MapCacheRegexCounterWFullCache/512         827883 ns     827364 ns        838
MapCacheRegexCounterWFullCache/1024       1870367 ns    1869385 ns        373
MapCacheRegexCounterWFullCache/2048       4600197 ns    4598091 ns        152
MapCacheRegexCounterWFullCache/4096      10612966 ns   10604399 ns        100
MapCacheRegexCounterWFullCache_BigO        212.54 NlgN     212.38 NlgN 
MapCacheRegexCounterWFullCache_RMS              8 %          8 % 
UMapCacheRegexCounterWEmptyCache/1          10674 ns      10667 ns      65217
UMapCacheRegexCounterWEmptyCache/2          10987 ns      10975 ns      62868
UMapCacheRegexCounterWEmptyCache/4          11631 ns      11624 ns      59360
UMapCacheRegexCounterWEmptyCache/8          12905 ns      12905 ns      52701
UMapCacheRegexCounterWEmptyCache/16         15509 ns      15505 ns      43209
UMapCacheRegexCounterWEmptyCache/32         21113 ns      21103 ns      31732
UMapCacheRegexCounterWEmptyCache/64         32453 ns      32453 ns      20805
UMapCacheRegexCounterWEmptyCache/128        57174 ns      57098 ns      11399
UMapCacheRegexCounterWEmptyCache/256       116683 ns     116575 ns       5245
UMapCacheRegexCounterWEmptyCache/512       319816 ns     319810 ns       1666
UMapCacheRegexCounterWEmptyCache/1024     2191742 ns    2191722 ns        242
UMapCacheRegexCounterWEmptyCache/2048     8046954 ns    8031371 ns         68
UMapCacheRegexCounterWEmptyCache/4096    19214806 ns   19202838 ns         34
UMapCacheRegexCounterWEmptyCache_BigO      376.45 NlgN     376.15 NlgN 
UMapCacheRegexCounterWEmptyCache_RMS           29 %         29 % 
UMapCacheRegexCounterWFullCache/1           10670 ns      10657 ns      65651
UMapCacheRegexCounterWFullCache/2           10942 ns      10931 ns      63966
UMapCacheRegexCounterWFullCache/4           11604 ns      11604 ns      60290
UMapCacheRegexCounterWFullCache/8           12786 ns      12786 ns      54490
UMapCacheRegexCounterWFullCache/16          15238 ns      15238 ns      46018
UMapCacheRegexCounterWFullCache/32          20581 ns      20581 ns      33979
UMapCacheRegexCounterWFullCache/64          31051 ns      31029 ns      22661
UMapCacheRegexCounterWFullCache/128         51708 ns      51674 ns      13475
UMapCacheRegexCounterWFullCache/256         93907 ns      93814 ns       7532
UMapCacheRegexCounterWFullCache/512        177394 ns     177350 ns       3970
UMapCacheRegexCounterWFullCache/1024       385160 ns     384709 ns       1803
UMapCacheRegexCounterWFullCache/2048       914159 ns     914141 ns        768
UMapCacheRegexCounterWFullCache/4096      1961302 ns    1959780 ns        359
UMapCacheRegexCounterWFullCache_BigO        39.94 NlgN      39.92 NlgN 
UMapCacheRegexCounterWFullCache_RMS             5 %          5 % 
U2MapCacheRegexCounterWEmptyCache/1         11027 ns      11015 ns      63266
U2MapCacheRegexCounterWEmptyCache/2         11198 ns      11194 ns      61700
U2MapCacheRegexCounterWEmptyCache/4         11606 ns      11593 ns      58385
U2MapCacheRegexCounterWEmptyCache/8         12625 ns      12625 ns      53832
U2MapCacheRegexCounterWEmptyCache/16        15298 ns      15298 ns      44542
U2MapCacheRegexCounterWEmptyCache/32        19217 ns      19217 ns      34760
U2MapCacheRegexCounterWEmptyCache/64        28160 ns      28151 ns      23579
U2MapCacheRegexCounterWEmptyCache/128       47140 ns      47139 ns      13297
U2MapCacheRegexCounterWEmptyCache/256       96590 ns      96422 ns       6070
U2MapCacheRegexCounterWEmptyCache/512      238415 ns     238189 ns       2545
U2MapCacheRegexCounterWEmptyCache/1024    2035766 ns    2034294 ns        246
U2MapCacheRegexCounterWEmptyCache/2048    7746305 ns    7746261 ns         70
U2MapCacheRegexCounterWEmptyCache/4096   18469318 ns   18468937 ns         35
U2MapCacheRegexCounterWEmptyCache_BigO     361.58 NlgN     361.57 NlgN 
U2MapCacheRegexCounterWEmptyCache_RMS          31 %         31 % 
U2MapCacheRegexCounterWFullCache/1          10966 ns      10959 ns      64137
U2MapCacheRegexCounterWFullCache/2          11179 ns      11166 ns      62407
U2MapCacheRegexCounterWFullCache/4          11617 ns      11609 ns      59882
U2MapCacheRegexCounterWFullCache/8          12633 ns      12615 ns      55804
U2MapCacheRegexCounterWFullCache/16         14694 ns      14687 ns      47736
U2MapCacheRegexCounterWFullCache/32         18413 ns      18388 ns      36883
U2MapCacheRegexCounterWFullCache/64         26942 ns      26926 ns      25928
U2MapCacheRegexCounterWFullCache/128        42973 ns      42963 ns      16133
U2MapCacheRegexCounterWFullCache/256        76500 ns      76411 ns       9057
U2MapCacheRegexCounterWFullCache/512       144348 ns     144153 ns       4796
U2MapCacheRegexCounterWFullCache/1024      289158 ns     288836 ns       2414
U2MapCacheRegexCounterWFullCache/2048      587287 ns     587273 ns       1174
U2MapCacheRegexCounterWFullCache/4096     1196472 ns    1195205 ns        588
U2MapCacheRegexCounterWFullCache_BigO       24.84 NlgN      24.82 NlgN 
U2MapCacheRegexCounterWFullCache_RMS           11 %         11 %
```