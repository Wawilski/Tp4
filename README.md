# Tp4

# Section 1.1

## Question 1.1.1

### How likely is it that two different strings produce an identical cryptographical hash with SHA-256?

Very unlikely, SHA-256 is designed such as, to find a collision, and so 2 string that produce the same hash, would take millions of attempts.   

### Think about how this algorithm works and try it with different inputs. Based on your understanding, try to come up with two different strings that produce the same checksum. This exercise will help you understand the limitations of checksum algorithms and why strong cryptographic hashes like SHA-256 are used in practice

aac
ada

# Section 1.2
## Question 1.2.1


### Identify the metadata of the compiled binary (e.g., size, permissions, architecture). Does the build process generate any intermediate files?

Size: 16kB
Persmission: executable
Architecture: GNU/Linux 4.4.0

### How does your output compare with that of other students?


### If you compile the program multiple times, do you always get the same output? Explain why (not).

No, the DATE and the TIME are compute at the compile time and will evolves during time. 

### If you run the program multiple times (without recompiling), do you always get the same output?

Yes, the binary won't change (as we don't recompile) so the output won't change ether

### If you share the output file with another student, does it work on their machine? What happens if their machine has a different architecture (e.g., Linux (x86) vs. macOS (ARM64))?

No, the binary is setup for a designed architecture, if it changes it will differ

### Is it a good practice to share the binary itself versus sharing the source code? Explain your reasoning.

No, there is a high security problem as the source code could do anything without us knowing it just with the binary

### Challenge: Research the SOURCE_DATE_EPOCH environment variable. Can you find a way to compile hello-world.c such that the timestamp embedded in the binary is always the same, regardless of when you run the compiler?

## Questions 1.2.2

### Compare your output values with those of other students. Are the sequences identical even if compiled on different distributions? Why is this behavior observed with rand()

Yes, they are

### If you run the program multiple times (without recompiling), do you always get the same output? Is this “randomness” reproducible?

Yes, without seed it is reproducible

## Questions 1.2.3

### If you compile the program multiple times, do you always get the same output? Explain why (not).

They are the same, there is no preprocessing so this will always build the same output

### If you run the program multiple times (without recompiling), do you always get the same output? Explain why (not).

No, the seed is based on time so it will always differ

### Does this version of the application behave differently (at runtime)? Explain why (not)?

## Question 1.2.4

### Montecarlo

```c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
  double x,y,z;
  int count = 0;
  time_t started = time(NULL);
  srand(started);
  int n = (int) rand() % 50000 + 1;

  printf("Compiled on %s at %s\n",__DATE__,__TIME__);
  printf("Execution started on %s",ctime(&started));

  for (int i = 0; i < n; i++) {
  x = (double) rand() / RAND_MAX;
  y = (double) rand() / RAND_MAX;
  z = x * x + y * y;
  if (z <= 1) count++;
  }

  printf("The approximation of Pi using %d iterations is %f \n", n, (count / (double) n) * 4);

  time_t stopped = time(0);
  printf("Execution stopped on %s",ctime(&stopped));

  return(0);
}

```


### What can you notice when you increase the number 𝑛 of iterations? Does the estimate of 𝜋 get closer to the actual value? How does the execution time change? Is this behaviour consistent with your expectations?


### Verify if the implementation is reproducible at build time, i.e., different compilations of the same (identical) source code consistently generate the same executable. To do so, generate a unique SHA-512 checksum for the compiled executable file using the sha512sum or shasum -a 512 command-line instruction. Is the checksum different for consecutive compilations of the same source code? Explain why (not). If the implementation is not build-time reproducible, please provide a new implementation (using a different filename) that is build-time reproducible.

It is not build time reproducible, the DATE and TIME values are computed on build time and so the binary changes,
If we want it to be build-time reproducible we cant show the DATE and TIME 

### Verify if the implementation is reproducible at run time, i.e., different executions of the same compiled source code produce exactly the same output result. If the implementation is not runtime reproducible, explain why, and provide a new implementation (using a different filename) that is runtime reproducible.

It is not runtime reproducible, the seed is set from the executional time so it is not reproducible
If we want it reproducible at run-time we need to change the seed

### Provide a version of the program that is both build-time and run-time reproducible. Explain how you achieved this

```c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
  double x,y,z;
  int count = 0;
  int seed = atoi(argv[1]);
  srand(seed);
  int n = argv[2]

  for (int i = 0; i < n; i++) {
  x = (double) rand() / RAND_MAX;
  y = (double) rand() / RAND_MAX;
  z = x * x + y * y;
  if (z <= 1) count++;
  }

  printf("The approximation of Pi using %d iterations is %f \n", n, (count / (double) n) * 4);

  return(0);
}

```

## Question 1.2.5

### How many parameters your version of the Monte Caorlo application form 2.6.1 should accept to be reproducible at buildtime and at runtime ? Motivate your answer.

1 for the seed (if we want a user based seed)
1 for the number of iteration

### Build the image using the single-stage and multi-stage Containerfile examples, compare and report their sizes. Motivate your answer.
```
Single-stage : 291MB
Multi-Stage : 8.75 MB
```
It can be explain by the fact that there are no build-tools in Multi-stage so the heavier tools aren't stocked in the Image

### Build the image using the multi-stage Containerfile and compare its size with the binary you obtained in the previous question. Why such a difference ? Motivate your answer.

```
Mutlistage : 8.75 MB
Binary : 16kB
```

The image still need to have complementary tool for the execution so it increases its size

### In the multi-stage Containerfile, what is the purpose of the COPY --from=build-env instruction ? Is it a good or bad idea to do that ? Motivate your answer.

It takes the environment of the machine creating the image
It may be a good idea because the binary would not work on other architectures if we cant have the environment but with this line we can 'obtain' it

### Reproducibility Challenge: Work with a partner. Try to build a container image for the Monte Carlo program that results in the EXACT same image ID (hash) on both machines. What obstacles did you encounter? (Consider timestamps, layer ordering, and base image pinning).

### When comparing with other students, do you all obtain the same output when running it with the same input parameters?

Yes, there is the same seed and the same number of iteration so the same output

### If you share the image using podman save and podman load, what is actually being transferred? Does this ensure the other student can reproduce your exact environment?

Yes

## Question 1.2.6
### Compare the resulting binary with other students. Is it the same?
###  Compare the installation path of the binary with other students. Is it the same?
###  If you build it multiple times, do you get the same resulting output?
###  What happens when you run nix shell nixpkgs#hello? How does it differ from nix profile add nixpkgs#hello?

It runs a new shell containing the package nix package hello, and so the access to the package is temporary.
"nix profile add nixpkgs#hello" add the package permanently in the user profile

### Briefly explain the role of the Nix store (/nix/store) and why it is immutable.
It is immutable to prevent accidental modification
###  What does nix flake lock do, and why is it critical for reproducibility?
It serves as a version control file and contains the dependecies version after entering the developement environment
### Purity & Sandboxing: Nix builds are executed in a “sandbox”. What would happen if your program tried to download a file or read your system’s /etc/passwd during the build phase in a Nix derivation? Why is this restriction important?
### Suppose an upstream package dependency updates unexpectedly. How does Nix ensure that your project remainsreproducible?
### You need to share a reproducible development environment with Java and GCC with some students. What would a minimal flake.nix file look like? Should you share the flake.lock file too?


