# Born 2 be Root

O projeto consiste na criação de uma VM (Máquina Virtual), onde faremos ajustes em:

- Sudo;
- SSH;
- UFW;
- Política de senhas;

# Criar a VM

## 1 - Hypervisor

Programa que permite criar e gerenciar VMs no computador. Utilizado para criar um ambiente seguro.
´
Tipo de Hipervisor, utilizaremos o `Tipo 2: Hoste`
Tipo | Nome | Utilizado em | Exemplos
-|-|-|-
 1 | Bare Metal | Funciona direto no hardware (igual sistema operacional). Utilizados em ambiente de servidores | VMWarevESXi, Microsoft Hyper-V, Proxmox
 2 | Hosted | Roda dentro do sistema operacional (Windowns, Linux), um programa dentro do sistema | VirtualBox, VMware

## 2 - Distribuiçao Linux

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
Ticar `Skip Unattended Installation` |  (pular instalacão não assistida),

**Skip Unattended Instalation**
 
Quando não marcamos (ticamos) esse elemento, o VirtualBox tenta automatizar o processo de instalação do sistema operacional, exemplos:

* Cria um usuário automaticamente;
* Define senha root por padrão;
* Pula a tela de seleção de idioma, teclado, fuso horário...

> A ideia do projeto é para criarmos todos esses elementos, um projeto do ZERO!

![alt text](/born_2_be_root/images/image.png)

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

![alt text](/born_2_be_root/image-1.png)

Próxima e ultima etapa, `Virtual Hard Disk`

Etapa | O que fazer?
---|---
Tamanho do Disco | 8gb
Ticar `Pre-allocate Full size`| VirtualBox já separa 8 GB de espaço físico no computador, mesmo que o Debian só use 1 GB por enquanto. NÃO marcar, vai ocupar espaço aos poucos, conforme o Debian for precisando.

![alt text](/born_2_be_root/images/image-2.png)

### Operar Sistema de Instalação

No programa: `Oracle VM VirtualBox Manager` e clicar em `Start`

Etapa | Descrição
-|-
`Start` | ligar a máquina
`Install` | iniciar a m'aquina
`English` | selecionar o idioma
`Select your location` | Other / Europe / Portugal
`Configure locales` | United Kingdom
`Configure the keybord` | American English (em casa o teclado está Portuguese)
Loading | ...
`Configure the network --> Hostname` | hostname da máquina virtual: **prondina42**
`Configure the network --> Domain name` | pular etapa
`Set up users and passwords --> root password` | Por enquanto, qualquer senha (grave-a!). 
Repita a senha na próxima etapa
`Set up users and passwords --> full name...` | O nome do usuário = Pamela Rondina
`Set up users and passwords --> username for your account` | prondina
`Set up users and passwords --> choose a password for the new user` | Por enquanto, qualquer senha (grave-a!). Repita a senha na próxima etapa
`Configure the clock` | Lisbon
Loading | ...

Questions:
1. O QUE 'E HOSTNAME??

### Partições

Etapa | Descrição
-|-
`Partition disks` | Guided - use entire disk and set up encrypyted LVM
`Partition disks --> Select disk to partition` | SCSI1 ... (a opçãp já aparece!)
`Partition disks --> Partitioning scheme` | Separate / home partition / Yes
Loading | ...
`Partition disks --> Encryption passphrase` | senha importante, cada start da VM ela será utilizada ex: @Ilbc42 (grave-a!). Repita a senha na próxima etapa
`Partition disks --> amount of volume...` | max (atalho para especificar o tamanho máximo)
Loading | ...
`Partition disks` | Finish partitioning...
`Partition disks` | Write the changes to disk? YES
Loading | ...
`Configure the package manager` | NO (essa etapa está questionando se possuo mais arquivos ISO para serem instalados)
`Configure the package manager --> Debian archive...` | vai espelhar o arquivo Debian da região --> Portugal \ deb.debian.org
`Configure the package manager --> HTTP...` | pule essa etapa (press Enter, está questionando se utiliza proxy ou não - um bloqueador de acesso a sites na internet) N
Loading | ...
`Configuring popular-contest` | uma pesquisa 'NO'
Loading | ...
`Software selection` | elimine todos os tiques + ENTER
Loading | ...
`Configuring grub-pc` | YES (carregador de Boot, necessário para iniciar a VM)
`Configuring grub-pc --> Device for boot...` | /dev/sda
Loading | ...
`Finish the installation` | Continue e VM criada! :)

Questions:
1. Por que estou separando as partições?
    Para que eu tenha espaços separados e que uma aplicação não interfira na outra.


# Antes de Acessar a VM --> Liberar acesso a outro terminal

Apos a VM criada, abrira o terminal da VM (que 'e pessimo para editar, apanhei bastante nele!)

Se estiver usando NAT, talvez não consiga acessar a VM diretamente. Recomendo mudar para Bridged Adapter ou Host-only Adapter:

1. Desligar a VM: File / Close
2. No `Oracle VM VirtualBox Manager`> Settings > Network.
3. Alterar de `NAT` para `Bridged Adapter`.
4. Reinicia a VM.

Antes, precisaremos instalar o SSH para demois acessar por outro terminal.

# Acessar a VM

Após as configurações da VM e criação das Partições, chegou o momento de acessar a VM. 

Etapa | Descrição
-|-
Solicita a senha encriptada | @Ilovebolo8
hotname da máquina | prondina42
nome do usuário | Pamela Rondina
login | username --> prondina 
senha | criada anteriormente
comando `lsblk` | Mostra no terminal 

![alt text](/born_2_be_root/images/image-3.png)



PRIMEIRO CRIAR A PORTA PARA ACESSO

SSH - OK
UFW
SUDO

# Configurar SSH - Parte 01 | 02

SSH: EXPLICAR!!!!!!!!!!!!!!!!!!!

> Aqui estaremos com usuario root --> Dono de Tudo, nao teremos necessidade de rodar os comandos com sudo!

Etapa | Descrição
-|-
`su -` | alterar para o root (incluir senha do hostname --> prondina42)
`apt update` | atualiza a lista de pacotes disponíveis nos repositórios
`apt install openssh-server -y` | Pacote de servidor que permite acessar a VM remotamente via terminal
`nano /etc/ssh/sshd_config` | abre as configurações do SSH
`#Port 22` | Alterar para `Port 4242` (eliminar o # para iniciar a ativacao da porta 4242)
`CTRL+X YES ENTER` | Salvar e sair
`service ssh status` | verifica o status do serviço SSH
`service ssh restart` | reinicia o SSH devido a nova porta 4242
`ssh -V` | verificar a versão do SSH (apenas para curiosidade!)

![alt text](/born_2_be_root/images/image-19.png)

Status SSH --> antes de `sudo service ssh restart` :

![alt text](/born_2_be_root/images/image-4.png)

Status SSH --> depois de `sudo service ssh restart` :

![alt text](/born_2_be_root/images/image-5.png)

# Conectar em dois terminais --> Linkar

**VM via SSH Port 4242**

Etapa | Descrição
-|-
No terminal da VM `hotsname -I` | recebe o valor de IP ex:10.12.123.45
No terminal desejado `ssh prondina@10.12.123.45 -p 4242` | yes

**********************************

**SSH de fora do terminal da VM Port 4242**

No app `Oracle VM VirtualBox Manager`.

Etapa | Descrição
-|-
`Settings` | ...
`Network` | clicar em Advanced\port Forwarding
`+` | Name: rule 1 \ Host Port: 4242 \ Guest Port: 4242
OK e OK | 

# Configurar Sudo

> Aqui estaremos com usuario root --> Dono de Tudo, nao teremos necessidade de rodar os comandos com sudo!

> `sudo`: permite o usuário executar comandos com privilégios de root. Root é o dono da P* toda.

Etapa | Descrição
-|-
`su -` | alterar para o root (incluir senha do hostname --> prondina42)
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
`secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"` | Limita os caminhos que podem ser usados ​​pelo sudo para executar comandos. 
`CTRL+X YES ENTER` | Salvar e sair
`sudo mkdir -p /var/log/sudo` | criar diretorio
`sudo touch /var/log/sudo/sudo.log` | criar arquivo de logs

```bash
Defaults    env_reset
Defaults    mail_badpass
Defaults    passwd_tries=3
Defaults    badpass_message="Password is wrong. Please try again."
Defaults    logfile="/var/log/sudo/sudo.log"
Defaults    log_input, log_output
Defaults    iolog_dir="/var/log/sudo"
Defaults    requiretty
Defaults    secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
```
![alt text](/born_2_be_root/images/image-18.png)

Questions:
1. O que é TTY para o sudo?

# Configurar SSH - Parte 02 | 02

Etapa | Descrição
-|-
`nano /etc/ssh/sshd_config` | abre as configurações do SSH
`#PermitRootLogin prohibit-password` | Alterar para `PermitRootLogin no`
`CTRL+X YES ENTER` | Salvar e sair

![alt text](/born_2_be_root/images/image-20.png)



# Configurar UFW

Etapa | Descrição
-|-
`sudo apt install ufw -y` | Pacote de servidor que instala o UFW (Uncomplicated Firewall), uma ferramenta simples e intuitiva para gerenciamento de firewall no Linux. Ela permite controlar o tráfego de entrada e saída da máquina, ajudando a proteger o sistema contra acessos não autorizados.
`sudo ufw enable` | ativar o firewall
`sudo ufw allow 4242` | permitir acesso a porta 4242 do SSH
`sudo ufw status` | visualizar o status das portas ALLOW (permitir)
`VERIFICAR !!! ` | verificar a versão do UFW (apenas para curiosidade!)

![alt text](/born_2_be_root/images/image-6.png)


# Política de Senhas

Etapa| Descrição
-|-
`sudo nano /etc/login.defs` | abrir configuração de senhas, ir em `Password aging controls`
`PASS_MAX_DAYS 99999` | alterar para `PASS_MAX_DAYS 30`
`PASS_MIN_DAYS 0` | alterar para `PASS_MIN_DAYS 2`
`CTRL+X YES ENTER` | Salvar e sair

![alt text]/born_2_be_root/images/(image-7.png)

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

![alt text](/born_2_be_root/images/image-8.png)

```bash
password requisite pam_pwquality.so retry=3 minlen=10 ucredit=-1 lcredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root
```

Etapa: Alterar senha do user | Descrição
-|-
`passwd` | Alterar senha do usuário atual para a nova política
Current Password | Senha atual
New password | nova senha (de acorda a nova política)
`sudo chage -l prondina` | Lista as informações da expiração da senha de um usuário.
`sudo chage -M 30 -m 2 -W 7 prondina` | Define regras de validade e segurança para a senha do user.
FYI `-M 30` | Máximo de 30 dias de validade da senha. Depois disso, o usuário é obrigado a trocar.
FYI `-m 2` | Mínimo de 2 dias entre trocas. 
FYI `-W 7` |  aviso com 7 dias de antecedência antes da senha expirar.

![alt text](/born_2_be_root/images/image-9.png)

# Esqueci a senha do USER! E agora?!

Pois e, ao testar na escola e em minha casa: fiz a grandissima manobra de esquecer a senha do user!

Bora ajustar! :)

Etapa | Descrição
-|-
No Start da VM | Na tela do GRUB digitar `e` (para editar a entrada do boot)
Encontra a linha `linux /vmlinux-6.1...quiet` | Adicione no final `init=/bin/bash`
`CTRL+X YES ENTER` | Salvar e sair
O sistema reinicia a VM no modo root | Vai solicitar a senha encriptada
`root@(none):/#` | adicionar `mount -o remount,rw /` (remonta o sistema com permissão de escrita)
Em seguida, `root@(none):/#` | adicionar `passwd user`
`New passaword` | adicionar nova senha conforme politicas de senhas e repita a etapa
`reboot` | caso de erro, `exec /sbin/init`
 
![alt text](/born_2_be_root/images/image-10.png)

FOTO CELULAR!!

# Criar `User` e `Groups`

Etapa: criar `user`| Descrição
-|-
`sudo adduser prondina` | ilustracao, nao criaremos um novo usuario para a VM, e sim na Avaliacao!

![alt text](/born_2_be_root/images/image-11.png)

Etapa: Visualizar informacoes do `user`| Descrição
-|-
`getent passwd prondina` | comando que busca informações do usuário no banco de dados do tipo passwd
Retorno `user:x:1001:1001:Pam:/home/user:/bin/bash` | No terminal teremos essa resposta.
user	Nome do usuário
FYI `x` |	Senha criptografada (fica em /etc/shadow)
FYI `1001` | 	UID (ID do usuário)
FYI `1001` |	GID (ID do grupo primário)
FYI `Pamela Rondina` | geralmente nome completo (comentario, descricao)
FYI `/home/user` | Diretório, home do usuário
FYI `/bin/bash` | Shell padrão do usuário
FYI `cut -d: -f1 /etc/passwd` | lista os usuarios existentes get


![alt text](/born_2_be_root/images/image-12.png)

Etapa: adicionar `group`| Descrição
-|-
`sudo addgroup user42` | cria um novo grupo

![alt text](/born_2_be_root/images/image-13.png)

Etapa: visualizar `group` criados| Descrição
-|-
`getent group` | visualiza grupos existentes
 `getent group nome_group` | verifica se um grupo especifico existe
 `getent group | cut -d: -f1`
 | mostra apenas os nomes dos usuarios: (`cut` --> corta o texto em colunas; `-d:` --> delimitador : ; `-f1` --> nome do grupo)
 `getent group | wc -l` | conta quantos grupos existem
 `groups user` | visualizar os grupos de um user especifico

Etapa: adicionar `user` a um `group`| Descrição
-|-
`sudo adduser prondina user42` | `user` adicionado ao `group`


# 09 Criacao do Script

> O Script deve rodar de 10 em 10 minutos no terminal.

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
## Ativar --> Crontab (robo de agendador de tarefas)

> Utilizado para poder executar o script de 10 em 10 minutos!
Etapa: | Descrição
|---|---|
No terminal, `sudo systemctl enable cron.service` | ativa o serviço con.service para iniciar automaticamente toda vez que o sistema for bootado (ligado/reiniciado).
`sudo systemctl start cron.service` | iniciar o cron.

> `sudo /usr/local/bin/monitoring.sh` --> rodar o script


## Ativar --> Script: 10 em 10 minutos!

Etapa: | Descrição
|---|---|
No terminal, `sudo crontab -u root -e` | 
Solicitar'a a senha | Em seguida, escolhar a opcao `1`
FYI `crontab` | agendador de tarefas
FYI `-u root` |  editar o crontab do usuário root
FYI `-e` | "editar" o arquivo crontab desse usuário

![alt text](/born_2_be_root/images/image-15.png)

Etapa: | Descrição
|---|---|
`@reboot sleep 40 && /usr/local/bin/monitoring.sh` | Quando o sistema for iniciado (rebootado), espere 40 segundos e então execute o script monitoring.sh.
No arquivo, `*/10 * * * * bash /usr/local/bin/monitoring.sh`
FYI */10	| minuto: execute a cada 10 minutos
FYI * |	hora: em todas as horas
FYI *	| dia do mês: Em todos os dias do mês
FYI *	| mês: em todos os meses
FYI * | dia da semana: em todos os dias da semana

![alt text](/born_2_be_root/images/image-16.png)

## Criar --> aquivo de Script

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

#### A arquitetura do seu sistema operacional e sua versão do kernel.

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

#### Disk Usage: 1009/2Gb (49%) --> Memoria Disk 

**Antes de comecar: para conhecimento!**

> Todas Particoes montadas no sistema `df -h`
Permitir que o script seja executado sem uma senhaUse% Mounted on
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
#Disk Usage: 1009/2Gb (49%)á tranquilo, vou te ajudar a montar o script com as explicações para você sacar tudo de verdade e se 
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
ning: Permanently added '[10.12.243.76]:4242' (ED25519) to the list of known hosts.
prondina@10.12.243.76's password: 
Linux prondina42 6.1.0-37-amd64 #1 SMP PREEMPT_DYNAMIC Debian 6.1.140-1 (2025-05-22) x86_64

The programs included with the Debian GNU/Linux system are free software;
the exact distribution terms for each program are described in the
individual files in /usr/share/doc/*/copyright.

Debian GNU/Linux comes with ABSOLUTELY NO WARRANTY, to the extent
permitted by applicable law.
Last login: Thu Jun 26 12:37:37 2025 from 10.12.243.76
prondina@prondina42:~$ sudo nano /usr/local/bin/monitoring.sh 
[sudo] password for prondina: 
prondina@prondina42:~$ sudo nano /usr/local/bin/monitoring.sh 
prondina@prondina42:~$ sudo /usr/local/bin/monitoring.sh 
m dado momento.

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

### Last boot: 2021-04-25 14:45

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

### LVM use: yes

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


### Connections TCP : 1 ESTABLISHED

> Mostrar o número de conexões TCP que estão no estado ESTABLISHED.

```bash
connect_tcp=$(ss -ta | grep ESTAB | wc -l
)

echo "#Connections TCP: $connect_tcp ESTABLHISED"
```

```c
#Connections TCP : 1 ESTABLISHED
```

Etapa:  | Descrição
-|-
`ss` | Mostra sockets, ou seja, conexões de rede
`-t` | Filtra só conexões TCP (o "T" do TCP) 
`-a` | Mostra todas as conexões (ativas e em escuta) 
`grep ESTAB` | Filtra só as que estão estabelecidas
`wc -l` | Conta quantas conexões tem (quantas linhas aparecem) 

### User log: 1

> Quantos usuários estão atualmente conectados/logados no sistema.

```bash
user_log=$(who | wc -l)

echo "#User log: $user_log"
```

```c
#User log: 1
```

Etapa:  | Descrição
-|-
`who` | Mlista os usuários logados no momento (nome, terminal, horário etc.)
`wc -l` | conta quantas linhas existem (cada linha = 1 usuário conectado)

### Network: IP 10.0.2.15 (08:00:27:51:9b:a5)

> Descobrir o IP da Maquina e o endereco MAC

- O endereço IP: interface de rede (da VM)
- O endereço MAC: dessa mesma interface 

```bash
ip_address=$(hostname -I | awk '{print $1}')
ip_mac=$(ip link | grep ether | awk '{print $2}')

echo "#Networking: $ip_address ($ip_mac)"
```

```c
#Network: IP 10.0.2.15 (08:00:27:51:9b:a5)
```

Etapa:  | Descrição
|---|---|
`hostname -I` | Mostra os endereços IP atribuídos às interfaces de rede 
`awk '{print $1}'` | Imprime a primeira coluna ip link
`ip link` | Mostra as interfaces de rede do sistema
`grep ether` | contém o endereço MAC da interface 
`awk '{print $2}` | Imprime a segunda coluna

### Sudo : 42 cmd

> 
```bash
sudo=$(journalctl -q _COMM=sudo | grep COMMAND | wc -l)
echo "#Sudo: $sudo"
```

```c
#Sudo : 42 cmd
```

Etapa:  | Descrição
|---|---|
`journalctl _COMM=sudo` | Puxa do `systemd journal` todas as entradas onde o programa executado foi “sudo”
`-q` | para nao ter hint no script
`grep COMMAND` | Filtra só as linhas que têm a palavra “COMMAND
`wc -l` | Conta quantas linhas sobraram depois do filtro, ou seja, quantos comandos foram realmente executados via sudo.
---------------------------------

### Script Finalizado

```bash
#!/bin/bash

#Arquitetura
arch=$(uname -a)

#Processador fisico
cpu_physical=$(lscpu | grep Socket | awk '{printf $2}')

#Processador Virtual
vcpu=$(nproc)

#Memory Usage
memory_usage=$(free -m | grep Mem | awk '{printf("%d/%dMB (%.2f%%)", $3, $2, $3/$2 * 100)}')

#Disk Usage
disk_usage=$(df -BG / | awk 'NR==2 {printf("%d/%dGb (%.0f%%)", $3, $2, $3/$2 * 100)}')

#CPU Load
cpu_load=$(top -bn1 | grep "Cpu(s)" | awk '{printf("%.1f%%", 100 - $8)}')

#Last boot
last_boot=$(who -b | awk '{print($3,$4)}')

#LVM use
lvm_use=$(lsblk | grep -q "lvm" && echo "yes" || echo "no")

#Connections TCP
connect_tcp=$(ss -ta | grep ESTAB | wc -l)

#User log
user_log=$(who | wc -l)

#Networking
ip_adress=$(hostname -I | awk '{printf $1}')
ip_mac=$(ip link | grep ether | awk '{printf $2}')

#Sudo cmd
sudo=$(journalctl -q _COMM=sudo | grep COMMAND | wc -l)

wall -q "#Architecture: $arch
#CPU physical: $cpu_physical
#vCPU: $vcpu
#Memory Usage: $memory_usage
#Disk Usage: $disk_usage
#CPU load: $cpu_load
#Last boot: $last_boot
#LVM use: $lvm_use
#Connections TCP: $connect_tcp ESTABLISHED
#User log: $user_log
#Networking: $ip_adress ($ip_mac)
#Sudo: $sudo cmd
"
```

-----------------------------------

## Rodar Script sem Senha

Etapa: | Descrição
|---|---|
No terminal, `sudo visudo` | abre as configurações do Sudo
Em `Allow members...` | Incluir `prondina ALL=(ALL) NOPASSWD:/usr/local/bin/monitoring.sh`

![alt text](/born_2_be_root/images/image-14.png)

--------------------------------------

### Assinatura --> signature.txt

Etapa: | Descrição
|---|---|
Desligue a VM | no aplicativo da Oracle VM
NO terminao host (e nao na VM!) | Acesse a sua VM `cd /home/user/sgoinfre/born2berrot`
busque o arquivo .vdi `shasum NomeDaMaquina.vdi` | gerara a assintura
Copie o texto | Crie um arquivo `signature.txt`

![alt text](/born_2_be_root/images/image-17.png)

> Esse arquivo em signature.txt que deve ser enviado no github da escola!





_________________________________________

### 💻 Resumo -> Comandos Uteis para a Avaliacao

AJUSTAR NA ORDEM DA AVALIACAO!

Etapa: Instrucoes Gerais | Descricao
|---|---|
An'alise do arquivo "signature.txt" | arquivo txt enviado para o Git da escola
Antes de clocar a maquina (JAMAIS DAR START NA ORIGINAL) | acessar a VM pelo terminal do proprio computador e fazer `shasum nomeProjeto.vdi`, guardar o numero em um arquivo.txt
Analisar o arquivos | `diff signature.txt arquivo2.txt
Onde seu arquivo `.vdi` esta localizado? | onde salvei a maquina `sgoinfre`
Clone da maquina original | Agora sim... let's go!
Verifique se não estão sendo usados snapshots | Ainda no terminal do computador e nao da VM `VBoxManage snapshot "born2beroot" list`

Etapa: Visao Geral do Projeto | Descricao
|---|---|
Como funciona uma máquina virtual |  Emula uma maquina utilizando a infraestrutura local da minha maquina atraves de um hipervisor **VirtualBox**
A sua escolha do sistema operacional | Conforme orientado pelo subject: Debian, por ser uma distribuicao mais estavel e segura
Diferenças básicas entre Rocky e Debian| Ambas sao distribuicao Linux, a maior diferenca 'e que Rock 'e baseado em RedHat. Debian 'e cnhecido por ser de codigo aberto, com uma ampla comunidade e Rocky ;e mais usado em ambiente corporativo apt e dnf
O objetivo das máquinas virtuais.| Seguimentar maquinas menores dentro de uma maquina principal 
Diferenca: aptitude e apt | Ambas sao utilizados para gerenciar pacotes e distribuicoes, apt utilizado na linha de comando e ja vem instalado, aptitude mais poderosa, interface interativa e resolucao automatica
O que APPArmor é | Ferramenta de seguranca do Linux 
Durante a defesa, um script deve exibir informações a cada 10 minutos | ANALISAR SCRIPT!!!!!!!!!!!!!!!!!!!!??????????

Etapa: Configuracao Simples | Descricao
|---|---|
Certifique-se de que a máquina não tem um ambiente gráfico no lançamento | a VM acessa diretamente o terminal
Uma senha será necessária antes de tentar se conectar a esta máquina | a senha criptografada @Ilbc42
Conecte-se com um usuário, que nao seja root | prondina @Ilp1 
Verifique se o serviço UFW é iniciado com a ajuda do aluno sendo avaliado | `sudo ufw status`
Verifique se o serviço SSH é iniciado com a ajuda do aluno sendo avaliado | `sudo service ssh status`
Verifique se o sistema operacional escolhido é Debian ou Rocky com a ajuda do aluno sendo avaliado | `uname -a`

Etapa | Descricao
|---|---|
O que 'e uma Maquina Virtual (VM)? | Uma m'aquina dentro da minha maquina
kernel | Uma forma de fazer o hardware e o software se comunicarem
O que 'e um Hypervisor? | Um programa que permite criar e gerenciar VMs, 'VirtualBox'
O que sao LVM (Particoes)? | ??????



O que 'e SSH? | Secure Shell --> protocolo de comunicacao segura que permite acessar outro computador remotamente via terminal
sudo systemctl start ssh ou ssh service start(?????) | Iniciar servico SSH

o que 'e UFW? |  Uncomplicated Firewall --> monitora o trafego de rede entrada e saída e decide bloquear ou permitir o tráfego. Controla o acesso as porta no caso 4242
sudo ufw allow 4242 | liberar a porta
sudo ufw deny 23 | bloquear a porta
sudo ufw reset | resetar tudo

???????? VERIFICAR A TAL PORTA 68

GRUPO E USERS


`sudo adduser new_user` | adiciona um novo usuario
`sudo addgroup new_group` | adiciona um novo grupo
`getent group` | lista os grupos existentes 
`getent group name_group` | verifica se o grupo existe
`sudo adduser name_user name_group` | adiciona user ao grupo especifico
`sudo service ssh status` ou `sudo systemctl status ssh` | verifica status ssh
`sudo service ssh restart` | reunicia o servico ssh

CRONTAB

cron? | programa para gerenciar scrips automaticos
 sudo crontab -u root -e | acessar script




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
`hostname -I ` (na VM) | buscar IP
`ssh user@IP -p 4242` | acessar de outro terminal
`sudo ufw status` | portas ativas
`sudo ufw allow nnumero_porta` | acessa e cria uma porta para ser o firewall
`nano /etc/pam.d/common-password` | acessa o arquivo para alterar a polica de senhas


***AJUSTAR ETAPA!!!

sudo service ssh status - verificar status do ssh (active de preferencia)
sudo service ssh start | caso nao esteja ativo
sudo nano /etc/ssh/sshd_config | arquivo de config de porta
Port 4242 | ativa
getent passwd pamela | confirmar user
sudo adduser pamela | criar user
sudo usermod -aG sudo pamela | NAO SEI

sudo systemctl enable ssh
______________________________



@Ilbc27

VERIFICAR!!!!
sudo apt remove aptitude



# Subject - PT

- Durante a defesa, você será questionada sobre o sistema operacional que escolheu.
Por exemplo, você deve saber as diferenças entre `aptitude` e `apt`, ou o que são `SELinux` ou `AppArmor.`
    - Resumindo: entenda o que você está usando! 🧠💻

- Um serviço SSH estará rodando na porta obrigatória 4242 da sua máquina virtual.
    - Por motivos de segurança, não pode ser possível conectar via SSH como root.

- O uso do SSH será testado durante a defesa, criando uma nova conta.
    - Você precisa, portanto, entender como o SSH funciona.

- Você precisa configurar o sistema operacional com o firewall UFW (ou firewalld no caso do Rocky Linux) e, portanto:

    - Somente a porta 4242 deve estar aberta na sua máquina virtual.
    - O firewall deve estar ativado quando a máquina virtual for iniciada.
    - Para Rocky, você deve usar o firewalld em vez do UFW.

- O nome da máquina (hostname) deve ser o seu login terminado com 42: prondina42 (hostname)
    - Você terá que modificar o hostname durante a avaliação.

    - Você precisa implementar uma política de senha forte.

    - Você deve instalar e configurar o sudo com regras rígidas.

    - Além do usuário root, um usuário com o seu login também deve estar presente.
        - Esse usuário deve pertencer aos grupos user42 e sudo.

 - Durante a defesa, você terá que:
    -    Criar um novo usuário
    - tribuí-lo a um grupo

- Para configurar uma política de senha forte, os seguintes requisitos devem ser seguidos:

    - A senha deve expirar a cada 30 dias
    - O número mínimo de dias antes de poder trocar a senha deve ser 2 dias
    - O usuário deve receber um aviso 7 dias antes da senha expirar

    - A senha deve:
    - Ter no mínimo 10 caracteres
    - Conter uma letra maiúscula, uma minúscula e um número
    - Não pode conter mais de 3 caracteres idênticos consecutivos
    - A senha não pode conter o nome do usuário.
    - A nova senha deve ter pelo menos 7 caracteres diferentes da senha antiga.

    - A seguinte regra não se aplica à senha do root:
        - Mas é claro: a senha do root ainda precisa obedecer à política de senha forte mencionada antes (10+ caracteres, maiúscula, minúscula, número, sem repetições etc).

    - Após configurar os arquivos de senha/política, você deve:
        - Alterar todas as senhas dos usuários da sua VM, incluindo a senha do root.

!!! 
> ALTERAR TBM A SENHA DO ROOT
!!!

Configuração segura do grupo sudo (muito importante!):

- Tentativas de autenticação via sudo devem ser limitadas a 3
    - Se o usuário errar a senha 3 vezes, já era!

- Deve ser exibida uma mensagem personalizada de erro se a senha do sudo estiver incorreta.

- Cada ação que usar sudo deve ser registrada, incluindo:

    - Tudo o que o usuário digitou (input)
    - E tudo que foi exibido (output)

!!! 
> VERIFICAR SE O ARQUIVO DE LOG ESTA CORRETO
!!!

 - Esses registros devem ser salvos em: /var/log/sudo/ (OK)

- O modo TTY (Terminal Teletype) deve estar habilitado
    👉 Isso garante que os comandos sudo só possam ser usados a partir de um terminal real (evita automatizações maliciosas, por exemplo)

- Os caminhos do sistema que sudo pode usar devem ser restritos, por segurança.
    🧭 Os caminhos permitidos devem ser como este exemplo:

`/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin`

- Script monitoring.sh – o Grande Final! 🎬

Você precisa criar um script simples chamado monitoring.sh.
🔧 Ele deve ser feito em bash.
`#! `

- Quando esse script deve rodar?
    - Toda vez que o servidor for iniciado (ligar a máquina)

!!!
> ASSIM QUE ABRE A MAQUINA JA RODA UM SCRIPT?


-   A cada 10 minutos, automaticamente
    - Dica: use o cron pra isso ⏱


- O comando `wall` vai te ajudar a exibir a mensagem para todos os usuários logados no terminal.

    - Nenhum erro deve aparecer quando o script rodar.

O que seu script deve mostrar sempre que for executado?

- A arquitetura do sistema e a versão do kernel
    (ex: Linux x86_64 com uname -a)
- O número de processadores físicos
    (ex: via lscpu | grep Socket)
- O número de processadores virtuais (vCPU)
    (ex: nproc)
- A quantidade de memória RAM usada/total e o percentual de uso
- O espaço em disco usado/total e o percentual de uso
- A utilização atual da CPU em porcentagem
- A data e hora do último boot
- Se o LVM está ativo ou não
- A quantidade de conexões TCP ativas
- A quantidade de usuários conectados
- O endereço IPv4 e o MAC address da máquina
- O número de comandos executados com sudo

Durante a defesa do projeto, você será questionada sobre como o script funciona e como interromper a execução dele sem editá-lo.
Isso significa que o script deve ser seguro, limpo, e fácil de parar 


-------------------------------------

Referencias | link
-|-
Instalar | [Debian](www.debian.org/distrib/netinst)
Guide | [born2beroot](https://github.com/chlimous/42-born2beroot_guide)
Nirmal Gope - Part 1 | [Youtube - Mandatory Part](https://www.youtube.com/watch?v=s2eM7L_etzo) 
Nirmal Gope - Part 2 | [Youtube - Mandatory Part](https://www.youtube.com/watch?v=3Vw0HlJHLTQ) 
