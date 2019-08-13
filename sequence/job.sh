#!/bin/sh
#SBATCH --job-name=popstacked
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --array=0-285

cd /users/home/bjarkig12/popstacked

primes=(999999937 999999929 999999893 999999883 999999797 999999761 999999757 999999751 999999739 999999733 999999677 999999667 999999613 999999607 999999599 999999587 999999541 999999527 999999503 999999491 999999487 999999433 999999391 999999353 999999337 999999323 999999229 999999223 999999197 999999193 999999191 999999181 999999163 999999151 999999137 999999131 999999113 999999107 999999103 999999067 999999059 999999043 999999029 999999017 999999001 999998981 999998971 999998959 999998957 999998929 999998921 999998917 999998903 999998869 999998863 999998843 999998801 999998789 999998777 999998693 999998689 999998687 999998683 999998663 999998653 999998641 999998639 999998627 999998621 999998617 999998609 999998563 999998537 999998533 999998509 999998507 999998501 999998459 999998423 999998369 999998339 999998309 999998269 999998261 999998243 999998203 999998183 999998173 999998147 999998143 999998141 999998137 999998119 999998107 999998081 999998059 999998023 999998017 999998003 999997967 999997891 999997871 999997811 999997793 999997787 999997771 999997769 999997717 999997697 999997679 999997673 999997643 999997639 999997627 999997589 999997577 999997571 999997567 999997561 999997543 999997489 999997457 999997403 999997357 999997331 999997309 999997301 999997279 999997267 999997249 999997241 999997237 999997181 999997133 999997099 999997081 999997067 999997049 999997021 999996989 999996983 999996919 999996913 999996901 999996827 999996779 999996749 999996727 999996709 999996707 999996689 999996677 999996671 999996649 999996643 999996611 999996587 999996541 999996493 999996469 999996407 999996383 999996359 999996341 999996329 999996317 999996311 999996307 999996301 999996269 999996259 999996247 999996227 999996223 999996199 999996181 999996149 999996131 999996113 999996091 999996073 999996071 999996043 999996037 999996031 999996029 999996007 999995993 999995959 999995921 999995911 999995903 999995819 999995813 999995809 999995803 999995749 999995741 999995713 999995701 999995681 999995677 999995663 999995651 999995629 999995627 999995621 999995611 999995599 999995567 999995561 999995531 999995431 999995419 999995413 999995393 999995377 999995341 999995291 999995273 999995261 999995257 999995239 999995141 999995111 999995107 999995093 999994987 999994979 999994973 999994951 999994913 999994903 999994883 999994867 999994861 999994843 999994837 999994823 999994813 999994781 999994771 999994763 999994753 999994747 999994741 999994703 999994693 999994691 999994651 999994649 999994613 999994609 999994603 999994549 999994537 999994531 999994507 999994487 999994439 999994433 999994427 999994423 999994397 999994381 999994379 999994357 999994343 999994337 999994321 999994313 999994309 999994297 999994277 999994273 999994267 999994241 999994201 999994189 999994159 999994157 999994129 999994123 999994097 999994091 999994081)
prime=${primes[SLURM_ARRAY_TASK_ID]}

echo "prime $prime"

for i in $(seq 1 4); do
    # Hack to deal with NFS issue
    sleep $(( RANDOM % 10 ))
    echo "trying"
    time ./sequence_mod $prime > sequence_${prime}.txt || continue
    break
done

echo "done"
