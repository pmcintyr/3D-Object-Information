# 3D-Object-Information
L’objectif principal de ce programme est d’afficher des informations concernant la forme décrite par l’utilisateur.
En particulier, nous souhaitons pouvoir afficher:
• le nombre total de sommets et de facettes ;
• le barycentre, c’est à dire la moyenne de tous les sommets ;
• pour un sommet donné, le nombre de facettes auxquelles il appartient et
leurs indices ;
• pour une facette donnée, le vecteur normal à cette facette et son aire.
Voici un exemple de déroulement du programme, que votre implémentation
devra être capable de reproduire :
Combien de sommets ? 5
Sommet 0 : 0.0 2.0 -2.0
Sommet 1 : -2.0 2.0 0.0
Sommet 2 : 0.0 2.0 2.0
Sommet 3 : 2.0 2.0 0.0
Sommet 4 : 0.0 0.0 0.0
Combien de faces ? 6
Face 0 : 0 2 3
Face 1 : 0 1 2
Face 2 : 4 3 2
Face 3 : 0 3 4
Face 4 : 4 1 0
Face 5 : 4 2 1
La forme contient 5 sommets et 6 facettes.
Le barycentre est : (0, 1.6, 0)
Le sommet 000 appartient à 4 facettes : 000 001 003 004
Le sommet 001 appartient à 3 facettes : 001 004 005
Le sommet 002 appartient à 4 facettes : 000 001 002 005
Le sommet 003 appartient à 3 facettes : 000 002 003
Le sommet 004 appartient à 4 facettes : 002 003 004 005
Face 000 : aire = 4, normale = (0, 1, 0)
Face 001 : aire = 4, normale = (0, 1, 0)
Face 002 : aire = 3.464, normale = (0.5774, -0.5774, 0.5774)
Face 003 : aire = 3.464, normale = (0.5774, -0.5774, -0.5774)
Face 004 : aire = 3.464, normale = (-0.5774, -0.5774, -0.5774)
Face 005 : aire = 3.464, normale = (-0.5774, -0.5774, 0.5774)

