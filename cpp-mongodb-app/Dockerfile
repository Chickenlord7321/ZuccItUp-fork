FROM ubuntu:24.04

# Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    libboost-all-dev \
    openssl \
    libssl-dev \
    git \
    pkg-config \
    && rm -rf /var/lib/apt/lists/*

# Build MongoDB C driver
WORKDIR /tmp
RUN git clone --depth 1 https://github.com/mongodb/mongo-c-driver.git && \
    cd mongo-c-driver && \
    mkdir cmake-build && \
    cd cmake-build && \
    cmake -DENABLE_AUTOMATIC_INIT_AND_CLEANUP=OFF .. && \
    make -j4 && \
    make install && \
    ldconfig

# Build MongoDB C++ driver
RUN git clone --depth 1 https://github.com/mongodb/mongo-cxx-driver.git && \
    cd mongo-cxx-driver && \
    mkdir cmake-build && \
    cd cmake-build && \
    cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local .. && \
    make -j4 && \
    make install && \
    ldconfig

# Copy application source
WORKDIR /app
COPY . .

# Build application
RUN mkdir -p build && \
    cd build && \
    cmake .. && \
    make -j4

# Expose port for future extensions
EXPOSE 8080

# Set environment variables
ENV MONGODB_URI=mongodb+srv://keenan:Mowgli4$@cluster0.oorsnye.mongodb.net/?appName=Cluster0
ENV MONGODB_DATABASE=myapp
ENV APP_ENV=production

# Run application
ENTRYPOINT ["./build/mongodb_app"]
