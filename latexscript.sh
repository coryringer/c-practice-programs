#!/bin/sh

# Print function
echo "f(x, y) = x + (1 + 2 + ... + y)"

# Get numbers
echo -n "Enter x: "
read X_ans
echo -n "Enter y: "
read Y_ans

# Get f(x, y), set f(x, y) to variable
NEW_NUM=$(./add-one-thru-m $X_ans $Y_ans)

# Output to LaTeX file
# entire text output 'using cat'
cat > output.tex << EOF
\documentclass[12pt, letterpaper, fleqn]{article}
\usepackage[T1]{fontenc}
\usepackage{mathptmx}
\usepackage{graphicx}

\begin{document}
  \$f(x, y) = x + (1 + 2 + ... + y)$

  \$f($X_ans, $Y_ans) = $NEW_NUM\$
\end{document}}
EOF

# Compile LaTeX file to PDF
pdflatex output.tex

# Clean directory
rm *.aux *.log
