# Docker 

Docker is a command-line program, a background daemon, and a set of remote services.
Docker helps to simplify tasks like installing, running, publishing, and removing software.

UNIX-style OS have used the term *jail* to describe a modified runtime environment for a program that prevents that 
program from accessing protected resources. Later the term container was used for this type of environment.
Any software run with Docker is run inside a **Docker Container**.

**Virtual machines (VM)** provide virtual hardware on which an operating system and other programs can be installed.
Docker containers don't use hardware virtualization. Programs running inside Docker containers interface directly with 
the host's Linux kernel and can access only their own memory and resources as scoped by the container.

Docker runs natively on Linux and comes with a single virtual machine for OS X and Windows environments. 
Thus, software running in Docker containers need only be written once against a consistent set of dependencies.

Docker improves the portability of every program regardless of the language it was written in, the operating system it 
was designed for, or the state of the environment where it is running.

Docker completes the traditional container metaphor by including a way to package and distribute software - called a 
**Docker Image**.
A Docker image is a bundled snapshot of all the files that should be available to a program running inside a container.
We can create as many containers from an image as we want.
Containers that were started from the same image don't share changes to their file system.

When we distribute software with Docker, we distribute these images, and the receiving computers create containers from them.

Docker provides a set of infrastructure components that simplify distributing Docker images called registries and indexes.

## Using Docker

Note that Docker runs as the root user on our system (Debian 10).
```
$ sudo systemctl start docker
$ sudo systemctl status docker

$ docker version
$ docker info
...
$ sudo systemctl stop docker
```

A **Docker Container** is an instance of that image running as a process.
There are many container specific commands we can use:

```
$ docker container help
Commands:
  attach      Attach local standard input, output, and error streams to a running container
  commit      Create a new image from a container's changes
  cp          Copy files/folders between a container and the local filesystem
  create      Create a new container
  diff        Inspect changes to files or directories on a container's filesystem
  exec        Run a command in a running container
  export      Export a container's filesystem as a tar archive
  inspect     Display detailed information on one or more containers
  kill        Kill one or more running containers
  logs        Fetch the logs of a container
  ls          List containers
  pause       Pause all processes within one or more containers
  port        List port mappings or a specific mapping for the container
  prune       Remove all stopped containers
  rename      Rename a container
  restart     Restart one or more containers
  rm          Remove one or more containers
  run         Run a command in a new container
  start       Start one or more stopped containers
  stats       Display a live stream of container(s) resource usage statistics
  stop        Stop one or more running containers
  top         Display the running processes of a container
  unpause     Unpause all processes within one or more containers
  update      Update configuration of one or more containers
  wait        Block until one or more containers stop, then print their exit codes
```

A **Docker Image** is the application we want to run. 
Also there are many commands we can use to manage images:

```
$ docker image help
Commands:
  build       Build an image from a Dockerfile
  history     Show the history of an image
  import      Import the contents from a tarball to create a filesystem image
  inspect     Display detailed information on one or more images
  load        Load an image from a tar archive or STDIN
  ls          List images
  prune       Remove unused images
  pull        Pull an image or a repository from a registry
  push        Push an image or a repository to a registry
  rm          Remove one or more images
  save        Save one or more images to a tar archive (streamed to STDOUT by default)
  tag         Create a tag TARGET_IMAGE that refers to SOURCE_IMAGE
```

Docker provides a mechanism for a user to inject environment variables into a new container.
The --env flag or -e for short can be used to inject any environment variable.


_Example:_ [Build and Run a Docker Image](docker-gcc/) 

*Egon Teiniker, 2020-2025, GPL v3.0*