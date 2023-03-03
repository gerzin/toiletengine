# toiletengine
<p align="left">
    <img src="https://img.shields.io/github/license/gerzin/toiletengine?style=flat-square"/>
    <img src="https://img.shields.io/github/contributors/gerzin/toiletengine?style=flat-square">
</p>
toiletengine is an UCI compliant chess engine.

## 🛠️ build instructions
The build system used for this project is Bazel.
Go in the `src` directory and run one of the following commands.

* to build the project:
```bash
bazel build //main:toiletengine
```
* to run the project:
```bash
bazel run //main:toiletengine
```
* to run the tests:
```bash
bazel test //<package>:<target>
```
# Warning
This is still a work-in-progress, any help is appreciated