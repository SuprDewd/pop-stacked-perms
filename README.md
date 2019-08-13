# Enumerating the pop-stacked permutations

A program to enumerate the pop-stacked permutations. Based on our technical
note TODO.

## Instructions

Navigate into either the `sequence` directory or the `triangle` directory,
depending on whether you want to count pop-stacked permutations, or pop-stacked
permutations grouped by number of ascending runs.

To count permutations up to length `N`, first perform some initialization by
running:
```bash
$ python ./init.py N
```

Then start the computation:
```bash
$ ./run_all.sh
```

Finally, recover the output as follows:
```bash
$ python ./combine.py
```

## Sequence

We have already counted the number of pop-stacked permutations of each length
up to `N=1000`. The results can be found in
[sequence.txt](https://github.com/SuprDewd/pop-stacked-perms/blob/master/sequence.txt).

## Triangle

We have already counted the number of pop-stacked permutations of each length,
grouped by number of ascending runs, up to `N=300`. The results can be found in
[triangle.txt](https://github.com/SuprDewd/pop-stacked-perms/blob/master/triangle.txt).

