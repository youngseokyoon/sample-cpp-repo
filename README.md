# Sample C++ Repository

이 repository는 GitHub Actions reusable workflows를 사용하는 C++ 프로젝트 예제입니다.

## 🏗️ 프로젝트 구조

```
sample-cpp-repo/
├── .github/
│   └── workflows/
│       └── ci.yml          # CI workflow
├── src/
│   ├── main.cpp            # 메인 애플리케이션
│   └── CMakeLists.txt      # CMake 설정
└── build/                  # 빌드 출력 (git ignored)
```

## 🚀 빌드 방법

### 로컬 빌드

```bash
# 1. 빌드 디렉토리 생성 및 설정
cmake -B build -S src -DCMAKE_BUILD_TYPE=Release

# 2. 빌드
cmake --build build --config Release

# 3. 실행
./build/bin/sample_app
```

### CI/CD

이 프로젝트의 CI workflow (`.github/workflows/ci.yml`)는 다음 단계를 수행합니다:

1. **Checkout**: 소스 코드 가져오기
2. **Build**: CMake로 C++ 코드 컴파일
3. **Upload**: 빌드 결과를 GitHub Artifacts에 업로드

## 🔄 Reusable Workflows 사용

현재는 inline workflow를 사용하지만, `central-workflows` repository를 GitHub에 push한 후
다음과 같이 reusable workflows를 사용할 수 있습니다:

```yaml
jobs:
  compile:
    uses: your-org/central-workflows/.github/workflows/compile-cpp.yml@main
    with:
      compiler: gcc
      build-type: Release
      cmake-args: "-DENABLE_TESTS=OFF"
      env-vars: '{"CC":"gcc-11","CXX":"g++-11"}'
```

## 📝 환경 변수 커스터마이징

각 프로젝트별로 다른 컴파일러 버전이나 빌드 옵션을 사용할 수 있습니다:

```yaml
env-vars: '{
  "CC": "gcc-12",
  "CXX": "g++-12",
  "CXXFLAGS": "-march=native"
}'
```
