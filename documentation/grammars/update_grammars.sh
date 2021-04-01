#!/bin/bash
python $HOME/code/NeMo/tools/text_denormalization/pynini_export.py $PWD/en_toy
cp $HOME/code/NeMo/tools/text_denormalization/tokenize_and_classify.grm en_toy/classify
cp $HOME/code/NeMo/tools/text_denormalization/verbalize.grm en_toy/verbalize
cd en_toy/classify; thraxmakedep tokenize_and_classify.grm ; make; cd ../../;
cd en_toy/verbalize; thraxmakedep verbalize.grm ; make; cd ../../;
