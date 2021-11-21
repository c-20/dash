# vboxmanage debugvm XPSP3 statistics
node=XPSP3
if [ "$1" = start ] ; then
  vboxmanage startvm $node
elif [ "$1" = key ] ; then
  vboxmanage controlvm $node keyboardputscancode 50 d0
  vboxmanage controlvm $node keyboardputscancode 50 d0
  vboxmanage controlvm $node keyboardputscancode 50 d0
  vboxmanage controlvm $node keyboardputscancode 1c 9c
else
  echo wut
fi

