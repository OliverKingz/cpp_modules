# Ford-Johnson Flow

Example input:

```text
11, 3, 9, 7, 2, 13, 8
```

## 1. Detect the straggler

There are 7 values, so one value cannot form a pair. The last value is kept as the straggler:

```cpp
--end;
straggler = *end;
```

The values are now divided into:

```text
Values used for pairs: 11, 3, 9, 7, 2, 13
Straggler:             8
```

`end` must be decremented before dereferencing it because `values.end()` points one position past the last element.

## 2. Create the pairs

The values are read two at a time. The larger value is stored first in each pair:

```text
11 and 3  ->  (11, 3)
9 and 7   ->  (9, 7)
2 and 13  ->  (13, 2)
```

The first value is the pair's winner. The second value is the pending value:

```text
Pairs: (11, 3), (9, 7), (13, 2)
```

## 3. Sort the pairs by their winners

`sortVectorPairs()` and `sortListPairs()` compare only the first value of each pair. The relationship between the two values is preserved while the pairs are moved.

The initial recursive split is:

```text
Left:  (11, 3)
Right: (9, 7), (13, 2)
```

The right side is split again:

```text
Left:  (9, 7)
Right: (13, 2)
```

Those sections contain one pair each, so they are already sorted. They are merged by comparing their winners:

```text
9 < 13
```

The right side becomes:

```text
(9, 7), (13, 2)
```

The top-level merge compares:

```text
Left:  (11, 3)
Right: (9, 7), (13, 2)
```

The comparisons are:

```text
9 < 11  -> (9, 7)
11 < 13 -> (11, 3)
13      -> (13, 2)
```

The sorted pairs are therefore:

```text
(9, 7), (11, 3), (13, 2)
```

The pending values stay attached to their original winners.

## 4. Build the two chains

The first values of the sorted pairs form the main chain:

```text
mainChain: 9, 11, 13
```

The second values form the pending chain:

```text
pending: 7, 3, 2
```

The straggler is still separate:

```text
straggler: 8
```

## 5. Insert the first pending value

The first pending value is inserted at the beginning:

```cpp
mainChain.insert(mainChain.begin(), pending.front());
```

The chain becomes:

```text
7, 9, 11, 13
```

## 6. Apply the Jacobsthal sequence

The code starts the Jacobsthal boundaries with:

```cpp
std::size_t previous = 1;
std::size_t current = 3;
```

The next boundaries are generated using:

```cpp
current = current + 2 * previous;
previous = upper;
```

This produces:

```text
1, 3, 5, 11, 21, 43, ...
```

For this example, `pending.size()` is 3. The first pending value, `7`, was already inserted, so the remaining values are inserted through the first group:

```cpp
previous = 1;
current = 3;
upper = min(3, pending.size()) = 3;
```

The group is traversed backwards:

```cpp
for (index = upper; index > previous; --index)
```

Therefore the insertion order is:

```text
pending[2] -> 2
pending[1] -> 3
```

### Insert `2`

Before insertion:

```text
7, 9, 11, 13
```

Binary insertion places `2` before `7`:

```text
2, 7, 9, 11, 13
```

### Insert `3`

Before insertion:

```text
2, 7, 9, 11, 13
```

Binary insertion places `3` between `2` and `7`:

```text
2, 3, 7, 9, 11, 13
```

The next boundary would be:

```cpp
current = 3 + 2 * 1 = 5;
previous = 3;
```

Since `previous < pending.size()` is now false, the pending insertion is complete.

## 7. Insert the straggler

The remaining value is `8`. It is inserted into the sorted main chain using `std::lower_bound`:

```text
2, 3, 7, 8, 9, 11, 13
```

## Complete flow

```text
Input:
11, 3, 9, 7, 2, 13, 8

Straggler:
8

Initial pairs:
(11, 3), (9, 7), (13, 2)

Pairs sorted by winners:
(9, 7), (11, 3), (13, 2)

Main chain:
9, 11, 13

Pending chain:
7, 3, 2

Insert first pending:
7, 9, 11, 13

Jacobsthal group:
boundary 1 -> 3
insertion order: pending[2], then pending[1]

Insert 2:
2, 7, 9, 11, 13

Insert 3:
2, 3, 7, 9, 11, 13

Insert straggler 8:
2, 3, 7, 8, 9, 11, 13
```

## Vector and list differences

The algorithmic order is the same for both containers. The difference is how a pending value is accessed:

### Vector

A vector has random-access iterators. The pending values can be reached directly by index:

```cpp
pending[index - 1]
```

### List

A list does not have random-access iterators. The code starts from `pending.begin()` and advances to the required position:

```cpp
std::list<int>::const_iterator value = pending.begin();
std::advance(value, index - 1);
```

Both implementations insert each value into the sorted chain with `std::lower_bound`.

## Important implementation note

This implementation uses the Jacobsthal order for inserting pending values. However, `std::lower_bound` currently searches the complete `mainChain` for every pending value.

A strict Ford-Johnson implementation limits each binary search to the winner associated with that pending value. Searching the complete chain still produces the correct sorted result, but it may perform more comparisons than the optimal Ford-Johnson version.
