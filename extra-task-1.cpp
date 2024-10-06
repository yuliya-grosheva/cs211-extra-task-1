#include <cassert>
#include <cmath> // ��� fabs

double seconds_difference(double time_1, double time_2) {
    return time_2 - time_1;
}

double hours_difference(double time_1, double time_2) {
    return (time_2 - time_1) / 3600.0; // 3600 ������ � ����
}

double to_float_hours(int hours, int minutes, int seconds) {
    assert(0 <= minutes && minutes < 60);
    assert(0 <= seconds && seconds < 60);

    return hours + minutes / 60.0 + seconds / 3600.0;
}

double to_24_hour_clock(double hours) {
    return fmod(hours, 24.0); // ���������� fmod ��� ��������� ������� �� �������
}

int get_hours(double time) {
    return static_cast<int>(time / 3600); // �������� ���������� �����
}

int get_minutes(double time) {
    return static_cast<int>((time / 60)) % 60; // �������� ���������� �����
}

int get_seconds(double time) {
    return static_cast<int>(time) % 60; // �������� ���������� ������
}

double time_to_utc(int utc_offset, double time) {
    return to_24_hour_clock(time - utc_offset); // ��������� ��������
}

double time_from_utc(int utc_offset, double time) {
    return to_24_hour_clock(time + utc_offset); // ��������� ��������
}

// ������ ������������� assert ��� ������������ �������
int main() {
    // ������������ seconds_difference
    assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < 1e-6);
    assert(fabs(seconds_difference(3600.0, 1800.0) + 1800.0) < 1e-6);

    // ������������ hours_difference
    assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) < 1e-6);
    assert(fabs(hours_difference(3600.0, 1800.0) + 0.5) < 1e-6);

    // ������������ to_float_hours
    assert(fabs(to_float_hours(0, 15, 0) - 0.25) < 1e-6);
    assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < 1e-6);

    // ������������ to_24_hour_clock
    assert(fabs(to_24_hour_clock(24) - 0) < 1e-6);
    assert(fabs(to_24_hour_clock(25) - 1) < 1e-6);

    // ������������ get_hours, get_minutes, get_seconds
    assert(get_hours(3800) == 1);
    assert(get_minutes(3800) == 3);
    assert(get_seconds(3800) == 20);

    // ������������ time_to_utc � time_from_utc
    assert(fabs(time_to_utc(+1, 12.0) - 11.0) < 1e-6);
    assert(fabs(time_from_utc(-1, 12.0) - 11.0) < 1e-6);

    return 0;
}
