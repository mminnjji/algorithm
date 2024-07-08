# Fractional Knapsack 구현
class Item:
    def __init__(self, weight, value):
        self.weight = weight
        self.value = value
        self.value_per_kg = value / weight

def fractional_knapsack(items, capacity):
    # 가치 대비 무게 비율로 정렬
    items.sort(key=lambda x: x.value_per_kg, reverse=True)

    total_value = 0  # 배낭에 담은 총 가치
    remaining_capacity = capacity  # 남은 배낭 용량

    for item in items:
        if remaining_capacity == 0:
            break

        if item.weight <= remaining_capacity:
            # 전체 아이템을 담을 수 있는 경우
            total_value += item.value
            remaining_capacity -= item.weight
        else:
            # 부분적으로 아이템을 담아야 하는 경우
            total_value += item.value_per_kg * remaining_capacity
            remaining_capacity = 0

    return total_value

# 사용 예시
items = [
    Item(60, 100000),  # A
    Item(100, 200000),  # B
    Item(120, 300000)  # C
]
capacity = 50

max_value = fractional_knapsack(items, capacity)
print(f"배낭의 최대 가치: {max_value}원")
