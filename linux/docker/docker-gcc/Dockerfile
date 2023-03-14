FROM frolvlad/alpine-gxx
COPY ./src/*.c /usr/src/
WORKDIR /usr/src/
RUN gcc -Wall -std=c99 -o sum_of_squares sum_of_squares.c
CMD ["./sum_of_squares"]