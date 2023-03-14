# Build and Run a Docker Image 

The `Dockerfile` defines the base image used (in which the `gcc` already exists, among other things), which source files are to be copied and built. Finally, the built program is started in the container.

```
FROM frolvlad/alpine-gxx
COPY ./src/*.c /usr/src/
WORKDIR /usr/src/
RUN gcc -Wall -std=c99 -o sum_of_squares sum_of_squares.c
CMD ["./sum_of_squares"]
```

The following example shows how this Docker image can be build and used to run the C program.

```
$ docker build -t gcc-application .

$ docker image ls
REPOSITORY            TAG       IMAGE ID       CREATED         SIZE
gcc-application       latest    af486cdcca63   24 hours ago    242MB
frolvlad/alpine-gxx   latest    6d4089b52158   2 months ago    242MB
hello-world           latest    feb5d9fea6a5   17 months ago   13.3kB
```

```
$ docker container run gcc-application
Sum of squares from 1 to 5 = 55
```

*Egon Teiniker, 2020-2023, GPL v3.0*