#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphe_adj_type.h"
#include "graphe_poids_type.h"
#include "graphe_liste_type.h"
#include "util_adj.h"
#include "util_poids.h"
#include "graphe.h"

GRAPHE fermeture_transistive(GRAPHE g)
{ // Passé pas valeur
  GRAPHE g1,g2;
  int modif=1,N;
  N=g.nb_sommets;
  /* attention, si on travaille sur g, on va mofidier l'argument */
  /* Pour conserver l'original - parce que sinon toutes les modif vont modifier le premier graphe*/
  g1=init_adj_mat(N);
  g2=init_adj_mat(N);
  /* duplication du graphe */
  for (int i=0;i<N;i++)
    for (int j=0;j<N;j++)
      {
        g1.adj[i][j]=g.adj[i][j];
        g2.adj[i][j]=g.adj[i][j];
      }
  while (modif!=0)
    {
      modif=0;
      for (int i=0;i<N;i++)
        for (int j=0;j<N;j++)
          {
            if (g1.adj[i][j]==1)  // on garde une copie sans modifications, pour eviter le iterference
              for(int k=0;k<N;k++)
                if ((g1.adj[j][k]==1) && (g2.adj[i][k]!=1)) // si on ne met pas le && on loop
                  {
                    g2.adj[i][k]=1;
                    modif=1;
                    /* printf("modif: %d -> %d\n",i,k); */
                  }
          }
      for (int i=0;i<N;i++)
        for (int j=0;j<N;j++)
          {
            g1.adj[i][j]=g2.adj[i][j];
          }
    }
  return g1;
}

/* calcul du plus court chemin avec l'algorithme de 
   dijkstra, à partir du somme numéro 'source' (sommets 
   numéroté à partir de 1. Le résultat est un tableau, 
   alloué par la fonction, qui contient tous les plus courts
   chemins avec 'source' */
int *dijkstra(GRAPHE_POIDS g,int source)
{
  int *dist, N, tous_marques=0;

  N=g.nb_sommets;
  dist=(int *)malloc(N*sizeof(int));
  if (dist==(int *)NULL)
    {
      printf("Error: no more memory\n");
      exit(EXIT_FAILURE);
    }
  // À chaque étape on évalue dist des sommets x non marquès
  // le sommet x de dist min est marqué
  for (int i=0;i<N;i++)
    dist[i]=214748364; /* Attention, si on utilise  2^31-1 ca ne marche pas 
                          (debordement de capacité) -> j'ai enlevé les unité */
  dist[source-1]=0;

  for (int i=0;i<N;i++)
    g.marque[i]=0;

  g.marque[source-1]=1;
 
  
  tous_marques=0;
  while (!tous_marques)
    {
      //un tour de la formule de Dijkstra
      for (int i=0;i<N;i++)
        {
          int min=214748364; 
          if (g.marque[i]==0)
            {/* prédecesseurs de i: colone i */
              for (int j=0;j<N;j++)
                {
                  if (g.adj[j][i]==1) // on regarde le predecesseur
                    {
                      /* min_j(dist[j]+P(ji)) */
                      int temp=dist[j]+g.poids[j][i];
                      min=temp<min?temp:min;
                    }
                }
              min=min<dist[i]?min:dist[i]; // si le min est inferieure on met min = min 
              dist[i]=min;
            }
        } 
      int min=214748364, index_min=0;
      tous_marques=1;
      //Marquage de la distance min trouvé
      // Pour verifier qu'ils sont tous marqués
      for (int i=0;i<N;i++)
        {
          if (g.marque[i]==0)
            {
              tous_marques=0;
              if (dist[i]<min)
                {
                  min=dist[i];
                  index_min=i;
                }
            }
        }
      g.marque[index_min]=1;
    }
  return dist;
}
