# Enumerating the pop-stacked permutations

A program to enumerate the pop-stacked permutations. Based on our paper
[Counting pop-stacked permutations in polynomial time](https://arxiv.org/abs/1908.08910).

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
This is sequence [A307030](https://oeis.org/A307030) on OEIS.

### Differential approximation
These 1000 terms give insight into the generating function for the number of
pop-stacked permutations. Using methods from differential approximation,
real and complex singularities of the generating function were approximated to
hundreds of digits, and then used to estimate constants in the asymptotic
growth of the sequence. The singularity approximations and estimated constants
can be found
[here](https://github.com/SuprDewd/pop-stacked-perms/blob/master/singularity_estimates.txt).


## Triangle

We have already counted the number of pop-stacked permutations of each length,
grouped by number of ascending runs, up to `N=300`. The results can be found in
[triangle.txt](https://github.com/SuprDewd/pop-stacked-perms/blob/master/triangle.txt),
where row `K` column `N` is the number of pop-stacked permutations of length
`N` with `K` ascending runs.
This is triangle [A309993](https://oeis.org/A309993) on OEIS.

### Rational generating functions
Each row, i.e. the number of pop-stacked permutations with a fixed number of
ascending runs, is shown to be rational in [Pop-stack sorting and its image:
permutations with overlapping runs](https://lipn.fr/~cb/Papers/popstack.pdf).
We used their construction to derive the generating function for the [first six
rows](https://github.com/SuprDewd/pop-stacked-perms/blob/master/f_k_correct.txt),
but then used our methods to derive conjectures for the [first 24
rows](https://github.com/SuprDewd/pop-stacked-perms/blob/master/f_k_guesses.txt).

