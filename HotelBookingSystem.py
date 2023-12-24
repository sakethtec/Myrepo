import sys
DATA_FILE = "hotel_data.txt"
MAX_ROOMS_PER_TYPE = 20
class Room:
    def __init__(self, room_number, room_type, room_price):
        self.room_number = room_number
        self.room_type = room_type
        self.room_price = room_price
    def __str__(self):
        return f"Room Number: {self.room_number}, Room Type: {self.room_type}, Price: {self.room_price}"
class Hotel:
    def __init__(self):
        self.rooms = {room_type: [] for room_type in ["Single Bedroom", "Double Bedroom", "Duplex", "Suite", "Apartment"]}
    def create_room(self):
        room_number = input("Enter the room number: ")
        print("Room Types:")
        print("1. Single Bedroom")
        print("2. Double Bedroom")
        print("3. Duplex")
        print("4. Suite")
        print("5. Apartment")
        choice = input("Enter the room type number: ")
        room_types = ["Single Bedroom", "Double Bedroom", "Duplex", "Suite", "Apartment"]
        room_type = room_types[int(choice) - 1] if choice.isdigit() and (1 <= int(choice) <= 5) else "Invalid choice"

        if room_type == "Invalid choice":
            print("Invalid room type.")
            return
        if self.is_room_filled(room_number, room_type) or len(self.rooms[room_type]) >= MAX_ROOMS_PER_TYPE:
            print(f"Cannot add more {room_type} rooms. Maximum limit reached.")
        else:
            room_price = self.get_room_price(room_type)
            room = Room(room_number, room_type, room_price)
            self.rooms[room_type].append(room)
            print(f"{room_type} room added successfully!")
    def is_room_filled(self, room_number, room_type):
        return any(room.room_number == room_number for room in self.rooms[room_type])
    def view_rooms(self):
        for room_type, rooms in self.rooms.items():
            print(f"\n{room_type} Rooms:")
            if not rooms:
                print("No rooms found.")
            else:
                for room in rooms:
                    print(room)
    def search_room(self):
        room_number = input("Enter the room number to search for: ")
        for room_type, rooms in self.rooms.items():
            for room in rooms:
                if room.room_number == room_number:
                    print(room)
                    return
        print("Room not found.")
    def delete_room(self):
        room_number = input("Enter the room number to delete: ")
        for room_type, rooms in self.rooms.items():
            for room in rooms:
                if room.room_number == room_number:
                    self.rooms[room_type].remove(room)
                    print(f"Deleted room: {room}")
                    return
        print("Room not found.")
    def save_data_to_file(self):
        with open(DATA_FILE, "w") as f:
            for room_type, rooms in self.rooms.items():
                for room in rooms:
                    f.write(f"{room.room_number},{room.room_type},{room.room_price}\n")
    def load_data_from_file(self):
        try:
            with open(DATA_FILE, "r") as f:
                for line in f:
                    room_number, room_type, room_price = line.strip().split(',')
                    room = Room(room_number, room_type, room_price)
                    self.rooms[room_type].append(room)
        except FileNotFoundError:
            pass
if __name__ == "__main__":
    hotel = Hotel()
    hotel.load_data_from_file()
    while True:
        print("\nWELCOME TO MY HOTEL")
        print("1. Add Room")
        print("2. View Rooms")
        print("3. Search Room")
        print("4. Delete Room")
        print("5. Save and Exit")
        choice = input("Enter your choice: ")
        if choice == "1":
            hotel.create_room()
        elif choice == "2":
            hotel.view_rooms()
        elif choice == "3":
            hotel.search_room()
        elif choice == "4":
            hotel.delete_room()
        elif choice == "5":
            hotel.save_data_to_file()
            print("Data saved. Exiting the system.")
            sys.exit(0)
        else:
            print("Invalid choice. Please try again.")