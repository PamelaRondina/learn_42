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

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
VERIFICAR DIFERENCA ENTRE AMBOS
Rocky e Debian

### Instalar Debian

No [site_oficial](www.debian.org/download) selecionar `amd64 debian-12.11.0...`, baixará arquivos.

> Erro no download --> se nao tiver espaço no computador! Baixará apenas arquivos que nao fará a instalaçao. 

- Arquivo ISO (apos baixar o Debian) - Semelhante a um CD com o arquivo do sistema para instalar.

Após baixar o arquivo, incluir o arquivo na pasta `home\sgoinfre`, diretório com maior espaço para realizar esse projeto.

Abrir um programa no computador chamado: Oracle VM VirtualBox Manager. 


**Resumo -> Instalar Debian** 
Etapa | . | Pra que serve?
-|-|-|-
1. Instalar Debian | [site_oficial](www.debian.org/download) selecionar `amd64 debian-12.11.0...` | Gera um arquivo ISO
2. Arquivo ISO | . | Gerado após realizar o download
3. Transferir ISO | Vai para a pasta `home\sgoinfre` | Diretòrio com maior espaço
4. Abrir VirtualBox | Um programa que ja esta instalado no pc | serve para realizar a leitura do arquivo ISO
5. 


______________________________

Referencias | url
-|-
Guide | [born2beroot](https://github.com/chlimous/42-born2beroot_guide)
Instalar | [Debian](www.debian.org/distrib/netinst)


