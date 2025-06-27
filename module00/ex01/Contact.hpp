/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:00:23 by ozamora-          #+#    #+#             */
/*   Updated: 2025/06/27 19:50:20 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "Utils.hpp"

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;

	public:
		// Constructors

		Contact();
		Contact(const std::string &fName, const std::string &lName,
			const std::string &nName, const std::string &phoneNbr,
			const std::string &darkSecret);

		// Setters

		void setFirstName(const std::string &fName);
		void setLastName(const std::string &lName);
		void setNickname(const std::string &nName);
		void setPhoneNumber(const std::string &phoneNbr);
		void setDarkestSecret(const std::string &darkSecret);

		// Getters

		const std::string &getFirstName() const;
		const std::string &getLastName() const;
		const std::string &getNickname() const;
		const std::string &getPhoneNumber() const;
		const std::string &getDarkestSecret() const;

		// Functions
		
		void printContact() const;
		bool isEmpty() const;
};

#endif