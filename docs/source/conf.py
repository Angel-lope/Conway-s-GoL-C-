import os
import sys


# -- Project information -----------------------------------------------------
project = "GameOfLife"
author = "David Adeakin"
copyright = "2024, David"

# -- General configuration ---------------------------------------------------
extensions = ["breathe"]

# Breathe Configuration
breathe_default_project = project
breathe_default_members = ("members", "undoc-members")

breathe_projects = {
    "GameOfLife": os.path.join(os.path.dirname(__file__), "../../build/docs/doxygen/xml")
}

templates_path = ["_templates"]
exclude_patterns = []

# -- Options for HTML output -------------------------------------------------
html_theme = "alabaster"
html_static_path = [os.path.abspath('_static')]





