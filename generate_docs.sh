echo "Generating documentation..."
doxygen Doxyfile && \
echo "Generating PDF..." && \
make -Cdocs/latex && \
echo "Moving PDF..." && \
mv "docs/latex/refman.pdf" "docs/R-Type_Engine.pdf" && \
echo "Done."