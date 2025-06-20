# Born 2 be Root

O projeto consiste em criar uma maquina virtual. (AJUSTAR RESUMO!!)

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

> Erro no download --> se nao tiver espaço no computador! Baixará apenas arquivos que nao fará a instalaçao. 

- Arquivo ISO (apos baixar o Debian) - Semelhante a um CD com o arquivo do sistema para instalar.

Após baixar o arquivo, incluir o arquivo na pasta `home\sgoinfre`, diretório com maior espaço para realizar esse projeto.

Abrir um programa no computador chamado: `Oracle VM VirtualBox Manager` e clicar em `New`.

- Name: Nomeie sua VM;
- Folder: Selecione o local de armazenamento: `pasta sgoinfre`;
- ISO Image: Escolha o arquivo download ISO (que deve estar na sgoinfre).
- Ticar `Skip Unattended Installation`, (pular instalacao nao assistida): 

**Skip Unattended Installation**
 
Quando nao marcamos (ticamos) esse elemento, o VirtualBox tenta automatizar o processo de instalacao do sistema operacional, exemplos:
* Cria um usuário automaticamente;
* Define senha root por padrão
* Pula a tela de seleção de idioma, teclado, fuso horário...

A ideia do projeto 'e para criarmos todos esses elementos.

FOTO!

Proxima etapa, alocar memoria:

- Base Memory: 1024mb 
- Processors: 1 
- NAO ticar `Enable EFI`
     - Extensible Firmware Interface (Ele pode causar problemas no boot ou dificultar instalações mais simples, como a do Debian.)

**Base Memory**

> RAM = Random Access Memory (memoria de curto prazo do computador)

- Memoria temporaria usada por programas abertos
- Quanto mais RAM, mais programas podem rodar ao mesmo tempo.
- A RAM 'e encerrada ao desligar o pc.

**Processors**

> O processador é o cérebro da máquina.
> Os núcleos são como mini-cérebros dentro dele.

- O processador executa tarefas.
- Núcleos = tarefas paralelas possíveis.

!!!

APRENDER MAIS!!!!!!

Proxima e ultima etapa, `Virtual Hard Disk`

- Criar com 8gb.
- Deixe a opção **"Pre-allocate Full size" MARCADA**.

!!!

- Marcar a opção, o VirtualBox já separa 8 GB de espaço físico no computador, mesmo que o Debian só use 1 GB por enquanto.
- NÃO marcar, vai ocupar espaço aos poucos, conforme o Debian for precisando.

### Operar Sistema de Instalacao

Etapa | Pra que serve?
-|-
`Start` | iniciar a maquina
`Install` | iniciar a instalacao do Debian
`Select language` | English
`Select your location` | others / Europe / Portugal
`Configure locales` | United States
`Configure the keyboard` | American English
Loading | ...
`Configure the network --> Hostname` | hostname da maquina virtual: **username + 42**
`Configure the network --> Domain name` | pular etapa
`Set up users and passwords --> new password` | Por enquanto, qualquer senha (grave-a!)
Repita a senha | na proxima etapa
`Set up users and passwords --> full name...` | O nome do usuario = Pamela Rondina
`Set up users and passwords --> username for your account` | username
`Set up users and passwords --> choose a password for the new user` | Por enquanto, qualquer senha (grave-a!)
`Configure the clock` | Lisbon
Loading | ...

Questions:

1. O QUE 'E HOSTNAME??
2. Por que pular Domain Name??

### Particoes

Etapa | Pra que serve?
-|-
`Partition disks` | Guided - use entire disk



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

Referencias | url
-|-
Guide | [born2beroot](https://github.com/chlimous/42-born2beroot_guide)
Instalar | [Debian](www.debian.org/distrib/netinst)


