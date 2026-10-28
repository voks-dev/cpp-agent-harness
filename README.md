# cpp-agent-harness
Кроссплатформенный консольный харнесс для локальных LLM-агентов на C++20.

Реализует agent loop: отплавляет историю диалога и JSON-схемы инструментов в локальную модель через Ollama, разбирает ответ на tool calls, выполняет инструменты и возвращает результаты модели до завершения задачи.

## Статус
В активной разработке.

## Платформы

| | Windows | Linux | macOS |
|---|---|---|---|
| Платформа | Windows 10+ | Ubuntu 20.04+ | macOS 12+ |
| Сборка | MSVC 19.3+ | GCC 13+ | Clang 10+ |
| Статус поддержки | основная среда | целевая | целевая |

## Требования

| Компонент | Выбор |
|---|---|
| Язык | C++20 |
| Система сборки | CMake >= 3.28 + ninja |
| LLM-бэкенд | [Ollama](https://ollama.com) (локально, `localhost:11434`) |
| Модель по умолчанию | `qwen2.5-coder:3b` |

Инструменты разработчика:
- [clang-format](https://clang.llvm.org/docs/ClangFormat.html) - для форматирования кода.

Зависимости подтягиваются автоматически через CMake FetchContent:
- [nlohmann/json v3.11.3](https://github.com/nlohmann/json) - сериализация. 
- [cpp-httplib v0.45.0](https://github.com/yhirose/cpp-httplib) - HTTP-клиент.
- [googletest v1.14.0](https://github.com/google/googletest) - unit-тесты.

## Сборка

Клонировать репозиторий github
```bash
git clone https://github.com/voks-dev/cpp-agent-harness.git
cd cpp-agent-harness
```
Для сборки необходима настройка окружения в соотвествии с требованиями описанными выше.

Debug:

```bash
cmake --preset debug
cmake --build --preset debug
```

Release:

```bash
cmake --preset release
cmake --build --preset release
```

## Тесты

Используется **GoogleTest** (подтягивается через FetchContent).

Запуск:

```bash
ctest --preset debug --output-on-failure
```

## Форматирование кода

Проект использует `clang-format` со стилем Google (`.clang-format` в корне).
Цель CMake:

```bash
cmake --build build --target format        # форматировать
```