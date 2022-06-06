```
git clone --recursive https://github.com/silhavyj/cpp_starter_project.git
```

```
cmake -S . -B build
make -C build
```

```
./build/src/myproject
```

```
./build/test/mytest
```

```
docker build -t myproject-docker-image .
```

```
docker run --name myproject myproject-docker-image
```

```
docker start -a myproject
```