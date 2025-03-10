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

_Example:_ Build the Docker image from the `Dockerfile`
```
$ cd docker-gcc
$ docker build -t gcc-application .

$ docker image ls
REPOSITORY            TAG       IMAGE ID       CREATED         SIZE
gcc-application       latest    af486cdcca63   24 hours ago    242MB
frolvlad/alpine-gxx   latest    6d4089b52158   2 months ago    242MB
```

_Example:_ Run the Docker container
```bash
$ docker container run gcc-application
Sum of squares from 1 to 5 = 55
```

_Example:_ List all containers, including the stopped ones
```bash
$ docker container ls -a
CONTAINER ID   IMAGE             COMMAND              CREATED         STATUS                     PORTS     NAMES
cd9fe58b9043   gcc-application   "./sum_of_squares"   3 minutes ago   Exited (0) 3 minutes ago             distracted_tesla
```

_Example:_ Remove the container
```bash
$ docker container rm cd9fe58b9043
cd9fe58b9043
```

_Example:_ List all images
```bash
$ docker image ls
REPOSITORY        TAG       IMAGE ID       CREATED         SIZE
gcc-application   latest    36506eef9f63   6 minutes ago   221MB
```

_Example:_ Remove the image
```bash
$ docker image rm gcc-application
Untagged: gcc-application:latest
Deleted: sha256:36506eef9f630a9f9eb8d0cffedcfe890613decb4c7e8662f37b22b97ab1dd3f
```

*Egon Teiniker, 2020-2025, GPL v3.0*