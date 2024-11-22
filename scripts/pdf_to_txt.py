# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    pdf_to_txt.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/22 14:24:01 by cyferrei          #+#    #+#              #
#    Updated: 2024/11/22 14:26:05 by cyferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import PyPDF2

def pdf_to_txt(pdf_path, txt_path):
    try:
        # Ouvrir le fichier PDF en mode lecture binaire
        with open(pdf_path, 'rb') as pdf_file:
            reader = PyPDF2.PdfReader(pdf_file)
            text = ""

            # Parcourir toutes les pages et extraire le texte
            for page in reader.pages:
                text += page.extract_text() + "\n"

        # Sauvegarder le texte extrait dans un fichier .txt
        with open(txt_path, 'w', encoding='utf-8') as txt_file:
            txt_file.write(text)

        print(f"Conversion réussie : {txt_path}")
    except Exception as e:
        print(f"Erreur lors de la conversion : {e}")

# Chemins des fichiers
pdf_path = "Defis Fantastiques 01 - Le Sorcier de la Montagne de feu.pdf"  # Remplacez par le chemin du fichier PDF
txt_path = "test.txt"        # Remplacez par le chemin du fichier texte

# Lancer la conversion
pdf_to_txt(pdf_path, txt_path)
