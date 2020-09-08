Achtar Mohamad 322CC


Am facut mai mult fisiere cum este cerut in pdf ,
unu de header si un main si unu pentru sa scriu functile pentru program .

la create fs

Am facut o functie de alocare unde ii dau un dublu pointer si aloc memorie pentru strucutra , 
si numele il dau direct ca cu strcpy crapa
programul , pointeri ii fac nul si cam asta e tot aici .

delete fs

dau free la root pentru de alocare de memorie .


 touch

Aloc memorie pentru structura  si cu strcpy adug numele si continutul in structura ,
si ma folosesc de pointerul din parametru pentru a accesa elementele din strucutra de fisiere Flist
fac un pointer Flist si il leg cu Directory ,
dupa aia adug fisiere la inceput si la sfersit exista ceva din inainte  ,
am sortat fisierile aici prin  functie de sortare pentru fisiere.

mkdir

Aloc memoria pentru strucutura adug numele in structura prin strcpy , tot asa ca si in file ma folosesc de pointru din parametri pentru 
a acesa un pointer de tip Dirlist care il aloc si il leg la Directory ,
 si adug la inceput si la sfercit  si sortezi directoarele prin  functie de sortat fisere 
, touch  si mkdir am avut nevoie sa gandesc pentru ele mult.


ls

Parcurg fie care sublista cu un while si fac afisare la fie care element in directorul curent.


pwd

Functia asta mi-a luat timp , verific daca directorul parinte este null daca este ii printezi numele ,
daca nu , printezi elementel , am facut un vector in care am bagat toate numele in el , in afisara 
normala se vedea totu invers .


cd 

E functie cam grea care trebuia sa parcurg Dirlist 
 la inceput trebuie sa intorc directorul parinte daca este introdus ".." am verficat cu stcmp am incercat cu == ,
 dar din cate am inteles nu merge  , dupa asta parcurg Dirlist si fac o compratie de nume daca e numele cautat il intorc
daca nu , printezi ca nu e acolo si intorc root ,
 am folosit un pointer care  cand citesc functia cd 
il fac sa fie egal cu functia pentru sa retin unde sunt.


la Main :

Citesc folosind fgets , prin while care merge daca tot timu este adevarat 
, o data am folosit pentru compratie cu if strcmp si o data strncmp 
ca uneoari merga asa si unoari asa , 
am vrut sa folosesc getline in loc de strtok care facea figuri dar am renuntat .

Resurse de inspiratie :

Geeksofgeek






