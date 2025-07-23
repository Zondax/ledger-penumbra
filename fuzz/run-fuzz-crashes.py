#!/usr/bin/env python3
"""
Local convenience wrapper for analyzing fuzzer crashes in ledger-penumbra project
"""

import os
import sys

# Add the common fuzzing module to path
current_dir = os.path.dirname(os.path.abspath(__file__))
project_root = os.path.dirname(current_dir)
common_fuzzing_path = os.path.join(project_root, "deps", "ledger-zxlib", "fuzzing")

sys.path.insert(0, common_fuzzing_path)

try:
    from analyze_crashes import main

    # Override default arguments to point to this project root
    if "--project-root" not in sys.argv:
        sys.argv.extend(["--project-root", project_root])

    # Run the common crash analyzer
    sys.exit(main())

except ImportError as e:
    print(f"Error: Cannot import common fuzzing module: {e}")
    print(f"Make sure deps/ledger-zxlib/fuzzing/analyze_crashes.py exists")
    sys.exit(1)