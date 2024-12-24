mkdir build
python3 -m venv build/env
source build/env/bin/activate
pip install -U pip setuptools wheel
pip install .