# Born 2 be Root

O projeto consiste na criação de uma VM (Máquina Virtual), onde faremos ajustes em:

- 
- Sudo;
- SSH;
- Política de senhas;


## 1 - Hypervisor

Programa que permite criar e gerenciar VMs no computador. Utilizado para criar um ambiente seguro.
´
Tipo de Hipervisor, utilizaremos o `Tipo 2: Hoste`
Tipo | Nome | Utilizado em | Exemplos
-|-|-|-
 1 | Bare Metal | Funciona direto no hardware (igual sistema operacional). Utilizados em ambiente de servidores | VMWarevESXi, Microsoft Hyper-V, Proxmox
 2 | Hosted | Roda dentro do sistema operacional (Windowns, Linux), um programa dentro do sistema | VirtualBox, VMware

## 2 - Distribuiçao Linux

!!!!!!!!

VERIFICAR DIFERENCA ENTRE AMBOS
Rocky e Debian


### Instalar Debian

No [site_oficial](www.debian.org/download) selecionar `amd64 debian-12.11.0...`, baixará arquivos.

> Erro no download --> se não possui espaço no computador! Baixará apenas arquivos que nao fará a instalação. 

- Arquivo ISO (após baixar o Debian) - é Semelhante a um CD com o arquivo do sistema para instalar.

Após baixar o arquivo, incluir o arquivo na pasta `home\sgoinfre`, diretório com maior espaço para realizar esse projeto.

Abrir programa: `Oracle VM VirtualBox Manager` e clicar em `New`.

Etapa | O que fazer?
---|---
Name | Nomeie sua VM;
Folder | Selecione o local de armazenamento: `pasta sgoinfre`
ISO Image | Escolha o arquivo download ISO (que deve estar na sgoinfre).
Ticar `Skip Unattended Installation` |  (pular instalaão não assistida),

**Skip Unattended Instalation**
 
Quando não marcamos (ticamos) esse elemento, o VirtualBox tenta automatizar o processo de instalação do sistema operacional, exemplos:

* Cria um usuário automaticamente;
* Define senha root por padrão;
* Pula a tela de seleção de idioma, teclado, fuso horário...

> A ideia do projeto é para criarmos todos esses elementos, um projeto do ZERO!

![alt text](image.png)

Proxima etapa, alocar memória:

Etapa | O que fazer?
---|---
Base Memory | 1024mb
Processors | 1
NAO ticar `Enable EFI` | Extensible Firmware Interface (Ele pode causar problemas no boot ou dificultar instalações mais simples, como a do Debian)

**Base Memory**

> RAM = Random Access Memory (memória de curto prazo do computador)

- Memória temporária usada por programas abertos;
- Quanto maior a RAM, mais programas podem rodar ao mesmo tempo;
- A RAM é encerrada ao desligar o pc.

**Processors**

> O processador é o cérebro da máquina.
> Os núcleos são como mini-cérebros dentro dele.

- O processador executa tarefas.
- Núcleos = tarefas paralelas possíveis.

MELHORAR: APRENDER MAIS!!!!!!

![alt text](image-1.png)

Próima e ultima etapa, `Virtual Hard Disk`

Etapa | O que fazer?
---|---
Tamanho do Disco | 8gb
Ticar `Pre-allocate Full size`| VirtualBox já separa 8 GB de espaço físico no computador, mesmo que o Debian só use 1 GB por enquanto. NÃO marcar, vai ocupar espaço aos poucos, conforme o Debian for precisando.

![alt text](image-2.png)

### Operar Sistema de Instalação

No programa: `Oracle VM VirtualBox Manager` e clicar em `Start`

Etapa | Descrição
-|-
`Start` | ligar a máquinilibx, raycasting | American English (em casa o teclado está Portuguese)
Loading | ...
`Configure the network --> Hostname` | hostname da máquina virtual: **username + 42**
`Configure the network --> Domain name` | pular etapa
`Set up users and passwords --> root password` | Por enquanto, qualquer senha (grave-a!). 
Repita a senha na próxima etapa
`Set up users and passwords --> full name...` | O nome do usuário = Pamela Rondina
`Set up users and passwords --> username for your account` | username
`Set up users and passwords --> choose a password for the new user` | Por enquanto, qualquer senha (grave-a!). Repita a senha na próxima etapa
`Configure the clock` | Lisbon
Loading | ...

Questions:
1. O QUE 'E HOSTNAME??
2. Por que pular Domain Name??

### Partições

Etapa | Descrição
-|-
`Partition disks` | Guided - use entire disk and set up encrypyted LVM
`Partition disks --> Select disk to partition` | SCSI2 ... (a opçãp já aparece!)
`Partition disks --> Partitioning scheme` | Separate / home partition / Yes
Loading | ...
`Partition disks --> Encryption passphrase` | senha importante, cada start da VM ela será utilizada ex: @Ilovebolo8 (grave-a!). Repita a senha na próxima etapa
`Partition disks --> amount of volume...` | max (atalho para especificar o tamanho máximo)
Loading | ...
`Partition disks` | Finish partitioning...
`Partition disks` | Write the changes to disk? YES
Loading | ...
`Configure the package manager` | NO (essa etapa está questionando se possuo mais arquivos ISO para serem instalados)
`Configure the package manager --> Debian archive...` | vai espelhar o arquivo Debian da região --> Portugal \ deb.debian.org
`Configure the package manager --> HTTP...` | pule essa etapa (press Enter, está questionando se utiliza proxy ou não - um bloqueador de acesso a sites na internet) NO (para a pesquisa!)
Loading | ...
`Software selection` | tire todos os tiques
Loading | ...
`Configuring grub-pc` | YES (carregador de Boot, necessário para iniciar a VM)
`Configuring grub-pc --> Device for boot...` | /dev/sda
Loading | ...
`Finish the installation` | Continue e VM criada! :)

Questions:
1. Por que estou separando as partições?
    Para que eu tenha espaços separados e que uma aplicação não interfira na outra.

### Acessar a VM

Após as configurações da VM e criação das Partições, chegou o momento de acessar a VM. Finalizamos o passo anterior, o terminal da VM estará aberto.

@Ilovebolocenoura42

Etapa | Descrição
-|-
Solicita a senha encriptada | @Ilovebolo8
hotname da máquina | prondina42
nome do usuário | Pamela Rondina
login | username --> prondina 
senha | criada anteriormente
comando `lsblk` | Mostra no terminal 

![alt text](image-3.png)

### Instalar Sudo

> `sudo`: permite o usuário executar comandos com privilégios de root. Root é o dono da P* toda.

Etapa | Descrição
-|-
`su -` | alterar para o root (incluir senha do usuário)
`apt update` | atualiza a lista de pacotes disponíveis nos repositórios
`apt install sudo` | instalar o pacote sudo, que permite executar comandos como root sem usar o `su -`
`adduser prondina sudo` | passar o usuário para o grupo sudo
`getent group sudo` | mostra quem está no grupo sudo 
`sudo reboot` | reinicia o sistema com segurança 
Reinicia a VM | Solicitará a senha encriptografada para acesso, e a login e senha usuário
`sudo -V` | verificar a versão do Sudo (apenas para curiosidade!)

> Agora liberado pois foi configurado o user para o grupo sudo.

**Configurar SUDO**

Etapa | Descrição
-|-
`sudo visudo` | abre as configurações do Sudo --> TODOS com `Defaults+(TAB)` (padrão)
`env_reset` | já consta
`mail_badpass` | já consta 
`passwd_tries=3` | 3 tentativas para conectar ao sudo
`badpass_message="QUALQUER TEXTO."` | Exibe uma mensagem personalizada ao usar uma senha errada com o sudo.
`logfile="/var/log/sudo/sudo.log"` | Define o arquivo de logs de entrada
`log_input, log_output` | entrada de logs e saída de logs
`iolog_dir="/var/log/sudo"` | Define o diretório para salvar logs de entrada e saída adicionais.
`requiretty` | Requer TTY para usar sudo.
`secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin **:/snap/bin**"` | Limita os caminhos que podem ser usados ​​pelo sudo para executar comandos. 
`CTRL+X YES ENTER` | Salvar e sair
`sudo mkdir -p /var/log/sudo` | criar diretorio
`sudo touch /var/log/sudo/sudo.log` | criar arquivo de logs

Questions:
1. O que é TTY para o sudo?

### Configurar SSH

Etapa | Descrição
-|-
`sudo apt install openssh-server -y` | Pacote de servidor que permite acessar a VM remotamente via terminal
`sudo nano /etc/ssh/sshd_config` | abre as configurações do SSH
`#Port 22` | Alterar para `Port 4242`
`#PermitRootLogin prohibit-passwaord` | Alterar para `PermitRootLogin no`
`CTRL+X YES ENTER` | Salvar e sair
`sudo service ssh status` | verifica o status do serviço SSH
`sudo service ssh restart` | reinicia o SSH devido a nova porta 4242
`ssh -V` | verificar a versão do SSH (apenas para curiosidade!)

Status SSH --> antes de `sudo service ssh restart` :

![alt text](image-4.png)

Status SSH --> depois de `sudo service ssh restart` :

![alt text](image-5.png)

### Configurar UFW

Etapa | Descrição
-|-
`sudo apt install ufw -y` | Pacote de servidor que instala o UFW (Uncomplicated Firewall), uma ferramenta simples e intuitiva para gerenciamento de firewall no Linux. Ela permite controlar o tráfego de entrada e saída da máquina, ajudando a proteger o sistema contra acessos não autorizados.
`sudo ufw enable` | ativar o firewall
`sudo ufw allow 4242` | permitir acesso a porta 4242 do SSH
`sudo ufw status` | visualizar o status das portas ALLOW (permitir)
`VERIFICAR !!! ` | verificar a versão do UFW (apenas para curiosidade!)

![alt text](image-6.png)

### Conectando...

**VM via SSH Port 4242**

Etapa | Descrição
-|-
`ssh prondina@127.0.0.1 -p 4242` | conectar
solicitará a senha -> yes
`exit` | para sair

**SSH de fora do terminal da VM Port 4242**

No app `Oracle VM VirtualBox Manager`.

Etapa | Descrição
-|-
`Settings` | ...
`Network` | clicar em Advanced\port Forwarding
`+` | Name: rule 1 \ Host Port: 4242 \ Guest Port: 4242
OK e OK | 

### Política de Senhas

Etapa| Descrição
-|-
`sudo nano /etc/login.defs` | abrir configuração de senhas, ir em `Password aging controls`
`PASS_MAX_DAYS 99999` | alterar para `PASS_MAX_DAYS 30`
`PASS_MIN_DAYS 0` | alterar para `PASS_MIN_DAYS 2`
`CTRL+X YES ENTER` | Salvar e sair

![alt text](image-7.png)

Etapa: Instalar Bliblioca PAM  | Descrição
-|-
`sudo apt-get install libpam-pwquality -y` | Biblioteca que integra ao PAM (Pluggable Authentication Modules) e permite controlar a complexidade das senha
`sudo nano /etc/pam.d/common-password` | acessar arquivo para configurar as senhas (pode pedir senha do usuário)
`password requisite pam_pwquality.so retry=3` | adicionar cada um dos itens abaixo, separados por um espaço
`minlen=10` | Senha deve ter no mínimo 10 caracteres
`ucredit=-1` | 1 letra maiúscula
`lcredit=-1` | 1 letra minúscula
`dcredit=-1` |  1 número (dígito)
`maxrepeat=3`| Não permite mais de 3 caracteres repetidos seguidos
`reject_username`| Rejeita senhas iguais ao nome do usuário
`difok=7`| Senha nova precisa ter pelo menos 7 caracteres diferentes da antiga
`enforce_for_root`| Aplica as mesmas regras até para o usuário root
`CTRL+X YES ENTER` | Salvar e sair
`sudo reboot` | reinicia o sistema com segurança 

![alt text](image-8.png)

Etapa: Alterar senha do user | Descrição
-|-
`passwd` | Alterar senha do usuário atual para a nova política
Current Password | Senha atual
New password | nova senha (de acorda a nova política)
`sudo chage -l user` | Lista as informações da expiração da senha de um usuário.
`sudo chage -M 30 -m 2 -W 7 user` | Define regras de validade e segurança para a senha do user.
`-M 30` | Máximo de 30 dias de validade da senha. Depois disso, o usuário é obrigado a trocar.
`-m 2` | Mínimo de 2 dias entre trocas. 
`-W 7` |  aviso com 7 dias de antecedência antes da senha expirar.

![alt text](image-9.png)

### Esqueci a senha do USER! E agora?!

Pois e, ao testar na escola e em minha casa: fiz a grandissima manobra de esquecer a senha do user!

Bora ajustar!

Etapa | Descrição
-|-
No Starta da VM | Na tela do GRUB digitar `e` (para editar a entrada do boot)
Encontra a linha `linux /vmlinux-6.1...quiet` | Adicione no final `init=/bin/bash`
`CTRL+X YES ENTER` | Salvar e sair
O sistema reinicia a VM no modo root | Vai solicitar a senha encriptada
`root@(none):/#` | adicionar `mount -o remount,rw /` (remonta o sistema com permissão de escrita)
Em seguida, `root@(none):/#` | adicionar `passwd user`
`New passaword` | adicionar nova senha conforme politicas de senhas e repita a etapa
`reboot` | caso de erro, `exec /sbin/init`
 
![alt text](image-10.png)

FOTO CELULAR!!

### Criar `User` e `Groups`

Etapa: criar `user`| Descrição
-|-
`sudo adduser user_name` | @umnovologin42

![alt text](image-11.png)

Etapa: Visualizar informacoes do `user`| Descrição
-|-
`getent passwd user` | comando que busca informações do usuário no banco de dados do tipo passwd
Retorno `user:x:1001:1001:Pam:/home/user:/bin/bash` | No terminal teremos essa resposta.
user	Nome do usuário
`x` |	Senha criptografada (fica em /etc/shadow)
`1001` | 	UID (ID do usuário)
`1001` |	GID (ID do grupo primário)
`Pamela Rondina` | geralmente nome completo (comentario, descricao)
`/home/user` | Diretório, home do usuário
`/bin/bash` | Shell padrão do usuário
`cut -d: -f1 /etc/passwd` | lista os usuarios existentesget


![alt text](image-12.png)

Etapa: adicionar `group`| Descrição
-|-
`sudo addgroup nome_grupo` | cria um novo grupo

![alt text](image-13.png)

Etapa: visualizar `group` criados| Descrição
-|-
`getent group` | visualiza grupos existentes
 `getent group nome_group` | verifica se um grupo especifico existe
 `getent group | cut -d: -f1`
 | mostra apenas os nomes dos usuarios: (`cut` --> corta o texto em colunas; `-d:` --> delimitador : ; `-f1` --> nome do grupo)
 `getent group | wc -l` | conta quantos grupos existem
 `group user` | visualizar os grupos de um user espscifico

Etapa: adicionar `user` a um `group`| Descrição
-|-
`sudo adduser nome_user nome_grupo` | `user` adicionado ao `group`

### Criacao do Script

**Modelo**

```c
#Architecture: Linux wil 4.19.0-16-amd64 #1 SMP Debian 4.19.181-1 (2021-03-19) x86_64 GNU/Linux
#CPU physical : 1
#vCPU : 1
#Memory Usage: 74/987MB (7.50%)
#Disk Usage: 1009/2Gb (49%)
#CPU load: 6.7%
#Last boot: 2021-04-25 14:45
#LVM use: yes
#Connections TCP : 1 ESTABLISHED
#User log: 1
#Network: IP 10.0.2.15 (08:00:27:51:9b:a5)
#Sudo : 42 cmd
```
Etapa: criar script | Descrição
-|-
`sudo touch /usr/local/bin/monitoring.sh` | criar arquivo para exeutar o script
`sudo chmod 755 /usr/local/bin/monitoring.sh` | alterar permissoes de arquivo ** abaixo ** 
`sudo nano /usr/local/bin/monitoring.sh` |  abrir arquivo para editar o script

Número	| Quem |	Permissão
|----|----|----|
7	| 🧑 Dono	| Leitura (4) + Escrita (2) + Execução (1) = 7
5	| 👨‍👩‍👧 Grupo	| Leitura (4) + Execução (1) = 5
5	| 🌍 Outros	| Leitura (4) + Execução (1) = 5

#### 1) A arquitetura do seu sistema operacional e sua versão do kernel.

```bash
#!/bin/bash

#Arquitetura
arch=$(uname -a)

echo "#Architecture: $arch
```
- Criado uma variavel `arch=$(uname -a)`: busca todas as informacoes necessarias
- `echo "#Architecture: $arch`: far'a com que imprima o script

```c
#Architecture: Linux prondina42 5.10.0-21-amd64 #1 SMP Debian 4.19.181-1 (2021-03-19) x86_64 GNU/Linux**
```

Etapa: O que o comando `uname -a` informa | Descrição
-|-
`Linux` | nome do sistema
`prondina42` | nome da máquina
`5.10.0-21-amd64` | versão do kernel (O QUE "E O KERNEL)
`x86_64` | arquitetura (64 bits)
`#1 SMP Debian 4.19.181-1 (2021-03-19) x86_64` | QUE ISSO??
`GNU/Linux` | sistema

#### O número de processadores físicos.

```bash
cpu_physical=$(lscpu | grep Socket | awk '{print $2}')

echo "#CPU physical: $cpu_physical"
```

```c
#CPU physical: 1
```

Etapa: contar quando processadores f'isicos a maquina possui| Descrição
-|-
`lscpu` | comando de informacoes sobre o CPU
`grep Socket` | filtra a linha onde aparece o texto `Socket`
`awk '{print $2}'` | quebra a linha em TABS e mostra a segunda opcao

#### O número de processadores virtuais.

```bash
vcpu=$(nproc)

echo "#vCPU: $vcpu"
```

```c
#vCPU: 1
```

Etapa: contar quando processadores virtuais a maquina possui| Descrição
-|-
`nproc` | comando de processadores virtuais

#### Memoria RAM utilizada.

```bash
memory_usage=$(free -m | grep Mem | awk '{printf("%d/%dMB (%.2f%%)", $3, $2, $3/$2 * 100)}')

echo "#Memory Usage: $memory_usage"
```

```c
#Memory Usage: 74/987MB (7.50%)
```
> Verificar o quanto de memoria RAM esta sendo utilizado no momento em MB e %

Etapa: Memoria RAM | Descrição
-|-
`free -m` | mostra o quanto de memoria em MB esta sendo utilizado (destaque para total($2) e used($3))
`awk '{printf("%d/%dMB (%.2f%%)", $3, $2, $3/$2 * 100)}')` | Vai printar o tamanho em MB da memoria usada e total e apresentar em %

#### #Disk Usage: 1009/2Gb (49%) --> Memoria Disk 

**Antes de comecar: para conhecimento!**

> Todas Particoes montadas no sistema `df -h`

```bash
Filesystem      Size  Used Avail Use% Mounted on
/dev/sda1        50G   20G   28G  42% /
/dev/sda2        10G    5G    5G  50% /home
tmpfs           2.0G     0  2.0G   0% /run
...
```

> Apenas a particao onde esta montado o diretorio raiz `/`

```bash
Filesystem      Size  Used Avail Use% Mounted on
/dev/sda1        50G   20G   28G  42% /
```

```bash
disk_usage=$(df -BG / | awk 'NR==2 {printf("%d/%dGb (%.0f%%)", $3, $2, $3/$2 *100)}')

echo "#Disk Usage: $disk_usage"
```

```c
#Disk Usage: 1009/2Gb (49%)
```
> Verificar o Disco Rigido

Etapa: Memoria DISK | Descrição
-|-
`df -BG /` | mostra o uso do disco `raiz /`, em GIGABYTES `-BG`, esta sendo utilizado 
`NR==2` | 2 linha --> Ignora o cabeçalho e pega só os dados.
`$3` e `$2` | destaque para total($2) e used($3)

```c 
#Disk Usage: 2/3Gb (49%)
3 == used ($3)
2 == total ($2)
67% == ($3 / $2 * 100)
```

> !!! Dica: `df -h / | awk '{print NR, $0}'`, mostra quantas linhas 

#### CPU load: 6.7% --> 

> Porcentagem de uso da CPU em um dado momento.

```bash
cpu_load=$(top -bn1 | grep "Cpu(s)" | awk '{printf("%1.f%%", 100 - $8)}')

echo "#CPU load: $cpu_load"
```

```c
#CPU load: 6.7%
```

Etapa: % CPU Load | Descrição
-|-
`top` | mostra em tempo real o que ocorre na maquina: uso de CPU, uso de memoria, quais processos estao rodando (atualiza de segundo em segundo) (Utilizar apenas o top nao deixa utilizar o grep, pois nao tem uma "foto - algo estatico")
`-b` | batch mode: modo robo, nao interativo. Escreve a saida no terminal com um texto simples
`n1` | execute apenas 1 atualizacao (1 leitura do sistema)
`grep "Cpu(s)"` | trabalha na linha tal
 `awk '{printf("%1.f%%", 100 - $8)}'` | 100 - a posicao de valor do ID --> 8 coluna (valor que nao esta sendo usado)  

Exemplo de `top -bn1 | grep "Cpu(s)"`
```c 
%Cpu(s):  6.7 us,  2.0 sy,  0.0 ni, 100  id,  0.1 wa,  0.0 hi,  0.2 si,  0.0 st
```

Etapa: Exemplo| Descrição
-|-
`us` | uso da CPU em tarefas de usuário (ex: programas) 
`sy` | uso da CPU em tarefas do sistema (ex: kernel)
`id` | quanto está ociosa (quanto NÃO está sendo usada)

Somar `us + sy` pra saber o uso total ou calcular `100 - id` (escolhi a segunda opcao).

#### Last boot: 2021-04-25 14:45

> Quando o sistema foi iniciado pela ultima vez?
> Boot é o processo de ligar e iniciar um sistema operacional em um computador.

```bash
last_boot=$(who -b | awk '{print($3,$4)}')

echo "#Last boot: $last_boot"
```

```c
#Last boot: 2021-04-25 14:45
#Last boot: AAAA-MM-DD HH:MM
```

Etapa:  | Descrição
-|-
`who -b` | mostra quem foi o ultimo boot
`awk '{print($3,$4)}'` | imprime os dados necessarios (, 'e o espaco)

#### LVM use: yes

> LVM: Logical Volume Manager: gerente de espaço de armazenamento no Linux!

```bash
lvm_use=$(lsblk | grep -q "lvm" && echo "yes" || echo "no" )

echo "#LVM use: $lvm_use"
```

```c
#LVM use: yes
```

Etapa:  | Descrição
-|-
`lsblk` | listar os dispositivos de blocos
`grep -q "lvm"` | localize em quiet (silencio), se achar retorna (0), caso nao (1)
`&& echo "yes"` | se achou, imprime yes
`(pipe2x) echo "no"` | e se nao, imprime no 


------------------------------------




```c

#Connections TCP : 1 ESTABLISHED
#User log: 1
#Network: IP 10.0.2.15 (08:00:27:51:9b:a5)
#Sudo : 42 cmd
```
------------------------------------


### 💻 Comandos básicos de gerenciamento Debian

 Comando | Explicação 
-|-|
`lsblk` | lista os discos e partições conectadas 
**SUDO** | ------
`su -` | alterar do usuario atual para o root
`apt` | gerenciador de pacotes do Debian/Ubuntu
`apt update` | atualiza a lista de pacotes disponíveis 
`apt install sudo` | instala o pacote sudo 
`adduser user sudo` | adiciona um usuário já criado ao grupo sudo 
`getent group sudo` | mostra quem está no grupo sudo 
`sudo reboot` | reinicia o sistema com seguranca 
`sudo -V` | versao do sudo
`sudo mkdir -p /va/log/sudo` | criar diretorio
`sudo touch /var/log/sudo/sudo.log` | criar arquivo de logs
**SSH** | ----------
`sudo apt install openssh-server -y` |pacote de servidor que permite acessar a VM remotamente via terminal
`sudo nano /etc/ssh/sshd_config` | abre as configuracoes do ssh
`sudo service ssh status` | verifica o status do serviço SSH
**UFW** | -----------
`sudo apt install ufw -y` | Pacote de servidor que permite ferramenta simples de firewall, que controla o tráfego de entrada e saída da sua máquina Linux.
`sudo ufw enable` | ativar o firewall
`sudo ufw allow 4242` | permitir acesso a porta 4242 do SSH
`sudo ufw status` | visualizar o status das portas ALLOW (permitir)
_________________________________________

**Resumo -> Instalar Debian** 

Etapa | . | Pra que serve?
-|-|-
1 [baixar Debian](www.debian.org/download) | selecionar `amd64 debian-12.11.0...` | Gera um arquivo ISO
2 Arquivo ISO | . | Gerado após realizar o download
3 Transferir ISO | Vai para a pasta `home\sgoinfre` | Diretòrio com maior espaço
4 Abrir VirtualBox | Um programa que ja esta instalado no pc | serve para realizar a leitura do arquivo ISO
5 ETAPA NEW


______________________________

Referencias | link
-|-
Instalar | [Debian](www.debian.org/distrib/netinst)
Guide | [born2beroot](https://github.com/chlimous/42-born2beroot_guide)
Nirmal Gope - Part 1 | [Youtube - Mandatory Part](https://www.youtube.com/watch?v=s2eM7L_etzo) 
Nirmal Gope - Part 2 | [Youtube - Mandatory Part](https://www.youtube.com/watch?v=3Vw0HlJHLTQ) 



@Ilbc27
