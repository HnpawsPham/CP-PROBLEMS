import os

cpp_count = sum(1 for root, _, files in os.walk('.') for f in files if f.endswith('.cpp'))
py_count = sum(1 for root, _, files in os.walk('.') for f in files if f.endswith('.py'))

with open("README.md", "r", encoding="utf-8") as f:
    content = f.read()

content = content.replace("{{CPP_COUNT}}", str(cpp_count))
content = content.replace("{{PY_COUNT}}", str(py_count))

with open("README.md", "w", encoding="utf-8") as f:
    f.write(content)
