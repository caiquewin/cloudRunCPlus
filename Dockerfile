# Etapa de build
FROM debian:bookworm AS build

RUN apt-get update && apt-get install -y \
    cmake g++ git make && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY . .

# Compila
RUN cmake -B build -S . && cmake --build build --target server

# Etapa final
FROM debian:bookworm-slim

WORKDIR /app
COPY --from=build /app/build/server .

EXPOSE 8080
CMD ["./server"]