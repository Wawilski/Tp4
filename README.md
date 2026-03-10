# Tp4

# Section 1.1

## Question 1.1.1

### How likely is it that two different strings produce an identical cryptographical hash with SHA-256?

Very unlikely, SHA-256 is designed such as, to find a collision, and so 2 string that produce the same hash, would take millions of attempts.   

# Section 1.2
## Question 1.2.1


### Identify the metadata of the compiled binary (e.g., size, permissions, architecture). Does the build process generate any intermediate files?

Size: 16kb
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


### What can you notice when you increase the number 𝑛 of iterations? Does the estimate of 𝜋 get closer to the actual value? How does the execution time change? Is this behaviour consistent with your expectations?


### Verify if the implementation is reproducible at build time, i.e., different compilations of the same (identical) source code consistently generate the same executable. To do so, generate a unique SHA-512 checksum for the compiled executable file using the sha512sum or shasum -a 512 command-line instruction. Is the checksum different for consecutive compilations of the same source code? Explain why (not). If the implementation is not build-time reproducible, please provide a new implementation (using a different filename) that is build-time reproducible.

It is not build time reproducible, the DATE and TIME values are computed on build time and so the binary changes,
If we want it to be build-time reproducible we cant show the DATE and TIME 

### Verify if the implementation is reproducible at run time, i.e., different executions of the same compiled source code produce exactly the same output result. If the implementation is not runtime reproducible, explain why, and provide a new implementation (using a different filename) that is runtime reproducible.

It is not runtime reproducible, the seed is set from the executional time so it is not reproducible
If we want it reproducible at run-time we need to change the seed

### Provide a version of the program that is both build-time and run-time reproducible. Explain how you achieved this


## Question 1.2.5

### How many parameters your version of the Monte Carlo application should accept to be reproducible at buildtime and at runtime ? Motivate your answer.
### Build the image using the single-stage and multi-stage Containerfile examples, compare and report their sizes. Motivate your answer.
### Build the image using the multi-stage Containerfile and compare its size with the binary you obtained in the previous question. Why such a difference ? Motivate your answer.
### In the multi-stage Containerfile, what is the purpose of the COPY --from=build-env instruction ? Is it a good or bad idea to do that ? Motivate your answer.
### Reproducibility Challenge: Work with a partner. Try to build a container image for the Monte Carlo program that results in the EXACT same image ID (hash) on both machines. What obstacles did you encounter? (Consider timestamps, layer ordering, and base image pinning).
### When comparing with other students, do you all obtain the same output when running it with the same input parameters?
### If you share the image using podman save and podman load, what is actually being transferred? Does this ensure the other student can reproduce your exact environment?
