# Base image
FROM gcc:9

# Update the image, install cmake, create 
# a directory for the application, etc.
RUN set -ex;                           \
    apt-get update;                    \
    apt-get install -y cmake;          \
    mkdir -p /app;                     \
    cd /app;

# Copy the source sode into the image
COPY . /app

# Compile the application
RUN set -ex;                           \
    cd /app;                           \
    cmake -S . -B build; make -C build

# Run the application
ENTRYPOINT ["/app/build/src/myproject"]