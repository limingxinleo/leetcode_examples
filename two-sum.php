<?php
class Solution
{

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target)
    {
        $new = [];
        foreach ($nums as $i => $num) {
            $new[] = [
                'id' => $i,
                'value' => $num
            ];
        }

        usort($new, function ($i, $v) {
            if ($i['value'] > $v['value']) {
                return 1;
            }
            return -1;
        });

        $count = count($new);
        foreach ($new as $item) {
            $id = $item['id'];
            $score = $item['value'];
            for ($j = $count - 1; $j >= 0; $j--) {
                $n = $score + $new[$j]['value'];
                if ($n == $target) {
                    if ($id < $new[$j]['id']) {
                        return [$id, $new[$j]['id']];
                    }
                    return [$new[$j]['id'], $id];
                }
                if ($n < $target) {
                    break;
                }
            }
        }
    }
}